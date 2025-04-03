#include <map>
template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	template<typename V_forward>
	interval_map(V_forward&& val)
	: m_valBegin(std::forward<V_forward>(val))
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	template<typename V_forward>
	void assign( K const& keyBegin, K const& keyEnd, V_forward&& val )
		requires (std::is_same<std::remove_cvref_t<V_forward>, V>::value)
	{
		if (!(keyBegin < keyEnd))
			return;

		auto it_low = m_map.lower_bound(keyBegin);
		V prev_val = (it_low == m_map.begin()) ? m_valBegin : std::prev(it_low)->second;

		auto it_high = m_map.lower_bound(keyEnd);
		V end_prev_val = (*this)[keyEnd];

		m_map.erase(it_low, it_high);

		if (prev_val != val) {
			auto [it, inserted] = m_map.insert_or_assign(keyBegin, std::forward<V_forward>(val));
			if (inserted) {
				// Check if the new entry is the first and equals m_valBegin
				if (it == m_map.begin() && it->second == m_valBegin) {
					m_map.erase(it);
					inserted = false;
				} else if (it != m_map.begin()) {
					auto prev_it = std::prev(it);
					if (prev_it->second == it->second) {
						m_map.erase(it);
						inserted = false;
					}
				}
			}
		}

		if (end_prev_val != val) {
			auto [it, inserted] = m_map.insert_or_assign(keyEnd, end_prev_val);
			auto next_it = m_map.upper_bound(keyEnd);
			if (next_it != m_map.end() && next_it->second == end_prev_val) {
				m_map.erase(it);
			}
		}
	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.