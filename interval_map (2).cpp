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
		if (!(keyBegin < keyEnd)) return;

		// Determine previous value
		V prev_val;
		auto it_prev = m_map.lower_bound(keyBegin);
		if (it_prev != m_map.begin()) {
			--it_prev;
			prev_val = it_prev->second;
		} else {
			prev_val = m_valBegin;
		}

		// Determine next value
		V next_val;
		auto it_next = m_map.upper_bound(keyEnd);
		if (it_next != m_map.begin()) {
			--it_next;
			next_val = it_next->second;
		} else {
			next_val = m_valBegin;
		}

		// Erase the range [keyBegin, keyEnd)
		auto it_erase_begin = m_map.lower_bound(keyBegin);
		auto it_erase_end = m_map.lower_bound(keyEnd);
		m_map.erase(it_erase_begin, it_erase_end);

		// Insert new interval start if necessary
		if (prev_val != val) {
			m_map.emplace(keyBegin, std::forward<V_forward>(val));
		}

		// Insert new interval end if necessary
		if (next_val != val) {
			auto it = m_map.find(keyEnd);
			if (it != m_map.end()) {
				if (it->second != next_val) {
					it->second = std::move(next_val);
				}
			} else {
				m_map.emplace(keyEnd, std::move(next_val));
			}
		} else {
			auto it = m_map.find(keyEnd);
			if (it != m_map.end() && it->second == val) {
				m_map.erase(it);
			}
		}

		// Ensure the first entry's value is not m_valBegin
		if (!m_map.empty() && m_map.begin()->second == m_valBegin) {
			m_map.erase(m_map.begin());
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