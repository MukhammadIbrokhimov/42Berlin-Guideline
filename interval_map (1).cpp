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
			
			// Find the lower and upper bounds in the existing map
			auto itLow = m_map.lower_bound(keyBegin);
			auto itHigh = m_map.lower_bound(keyEnd);
			
			// Find the value before keyBegin
			V prevValue = (itLow == m_map.begin()) ? m_valBegin : std::prev(itLow)->second;
			
			// Avoid unnecessary insertion if the interval already has the same value
			if (prevValue == val)
				return;
			
			// Modify m_map
			// Erase all elements in the range [itLow, itHigh) since they will be overwritten
			m_map.erase(itLow, itHigh);
			
			// Step 6: Insert new interval at keyBegin if necessary
			if (m_map.empty() || m_map.rbegin()->second != val)
				m_map[keyBegin] = val;
			
			//Restore previous value after keyEnd, if necessary
			if (itHigh != m_map.end() && itHigh->second == prevValue)
				m_map[keyEnd] = prevValue;
			else if (itHigh == m_map.end() && prevValue != val)
				m_map[keyEnd] = prevValue;
			
			// Ensure canonicity: Remove redundant entries with the same consecutive values
			auto it = m_map.begin();
			while (it != m_map.end()) {
				auto nextIt = std::next(it);
				if (nextIt != m_map.end() && it->second == nextIt->second)
					m_map.erase(nextIt);
				else
					++it;
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