//DAY 27



class TestDataEmptyArray {
public:
    static vector<int> get_array() {
        // complete this function
        vector<int> arr;
        return arr;
    }

};

class TestDataUniqueValues {
public:
    static vector<int> get_array() {
        // complete this function
        vector<int> arr;
        arr.push_back(5);
        arr.push_back(6);
        arr.push_back(4);
        arr.push_back(8);
        return arr;
    }

    static int get_expected_result() {
        // complete this function
        return 2;
    }

};

class TestDataExactlyTwoDifferentMinimums {
public:
    static vector<int> get_array() {
        // complete this function
        vector<int> arr;
        arr.push_back(5);
        arr.push_back(6);
        arr.push_back(4);
        arr.push_back(8);
        return arr;
    }

    static int get_expected_result() {
        // complete this function
        return 2;
    }

};

