//
//  minideque.h
//  minidequeproject
//

#ifndef minideque_h
#define minideque_h

#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <iostream>

template <typename T>
class minideque {
private:
	std::vector<T> fronthalf_;
	std::vector<T> backhalf_;

public:
	minideque() = default;                                   // do not change, C++ defaults are ok
	minideque(const minideque<T>& other) = default;          // rule of three
	minideque& operator=(const minideque<T>& other) = default;
	~minideque() = default;

	size_t size() const {             // TODO
		return fronthalf_.size() + backhalf_.size();
	}
	size_t fronthalfsize() const {    // TODO
		return fronthalf_.size();
	}
	size_t backhalfsize() const {     // TODO
		return backhalf_.size();
	}
	bool empty()  const {              // TODO
		if (fronthalf_.size() == 0 && backhalf_.size() == 0) {
			return true;
		} else {
			return false;
		} //if
	}

  // balance queue across both vectors if pop_front/back is requested on an empty vector
  // e.g., minideque has this:                  | ABCDEFG
  // after pop_front                        BCD | EFG (A discarded)
  // symmetric logic for converse case: ABCDEFG | ===> ABC | DEF (G discarded) after pop_back
	void pop_front() {  // TODO
		if (fronthalf_.empty() == false) { //back vector size irrelevant because front vector is not empty
			fronthalf_.pop_back();
		} else (fronthalf_.empty() == false && backhalf_.empty() == true) { //if only front vector is empty, shift half of back vector's values to the back vector
			int half = backhalf_.size() / 2; //half of back vector
			
			for (int i = half; i < backhalf_.size(); i++) { //from half point to the end of the back vector
				fronthalf_.push_back(backhalf_[i]); //push back the value at index i of the back vector to the front vector
				backhalf_.erase(fronthalf_.begin()+i); //erase from back vector
			} //for
			fronthalf_.pop_back(); //and then you pop it like its hot
		} //if
	} //pop_front
	void pop_back() {   // TODO
		if (backhalf_.empty() == false) { //front vector size irrelevant because back vector is not empty
			backhalf_.pop_back();
		} else (fronthalf_.empty() == false && backhalf_.empty() == true) { //if only back vector is empty, shift half of front vector's values to the back vector
			int half = fronthalf_.size() / 2; //half of front vector
			
			for (int i = half; i < fronthalf_.size(); i++) { //from half point to the end of the front vector
				backhalf_.push_back(fronthalf_[i]); //push back the value at index i of the front vector to the back vector
				fronthalf_.erase(backhalf_.begin()+i); //erase from front vector
			} //for
			backhalf_.pop_back(); //and then you pop it like its hot
		} //if
	} //pop_back

	void push_front(const T& value) {   // TODO
		fronthalf_.push_back(value);
	}
	void push_back(const T& value) {    // TODO
		backhalf_.push_back(value);
	}

	const T& front() const {   // TODO
		if (fronthalf_.empty() == false) { //if not empty
			return fronthalf_.back();
		} else { //if empty
			return backhalf_.front();
		} //if
	} //front
	const T& back() const {    // TODO
		if (backhalf_.empty() == false) { //if not empty
			return backhalf_.back();
		} else { //if empty
			return fronthalf_.front();
		} //if
	} //back
	T& front() {               // TODO
		if (fronthalf_.empty() == false) { //if not empty
			return fronthalf_.back();
		} else { //if empty
			return backhalf_.front();
		} //if
	} //front
	T& back() {                // TODO
		if (backhalf_.empty() == false) { //if not empty
			return backhalf_.back();
		} else { //if empty
			return fronthalf_.front();
		} //if
	} //back

	const T& operator[](size_t index) const {  // TODO
		if (fronthalf_.size() > index) { //if i'th element is in front vector
			return fronthalf_[fronthalf_.size() - (index + 1)];
		} else { //if i'th element is in back vector
			return backhalf_[index - fronthalf_.size()];
		} //if
	}
	T& operator[](size_t index) {              // TODO
		if (fronthalf_.size() > index) { //if i'th element is in front vector
			return fronthalf_[fronthalf_.size() - (index + 1)];
		} else { //if i'th element is in back vector
			return backhalf_[index - fronthalf_.size()];
		} //if
	}

	void clear() {  // TODO
		fronthalf_.clear();
		backhalf_.clear();
	}

	friend std::ostream& operator<<(std::ostream& os, const minideque<T>& dq) {    // do not change
		if (dq.empty()) { return os << "minideque is empty"; }

		dq.printFronthalf(os);
		os << "| ";
		dq.printBackhalf(os);
		os << ", front:" << dq.front() << ", back:" << dq.back() << ", size:" << dq.size();
		return os;
	}

	void printFronthalf(std::ostream& os=std::cout) const {                    // do not change
		if (empty()) { std::cout << "fronthalf vector is empty"; }

		for (typename std::vector<T>::const_reverse_iterator crit = fronthalf_.crbegin();
			crit != fronthalf_.crend(); ++crit) {
		os << *crit << " ";
		}
	}

	void printBackhalf(std::ostream& os=std::cout) const {                     // do not change
		if (empty()) { os << "backhalf vector is empty"; }

		for (typename std::vector<T>::const_iterator cit = backhalf_.cbegin();
			cit != backhalf_.cend(); ++cit) {
			os << *cit << " ";
		}
	}
};

#endif /* minideque_h */
