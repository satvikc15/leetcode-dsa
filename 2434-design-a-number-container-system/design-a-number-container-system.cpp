class NumberContainers {
public:
    unordered_map<int, int> cont;
    map<int, set<int>> numToIndices;

    NumberContainers() {

    }

    void change(int index, int number) {
        if (cont.count(index)) {
            int oldNumber = cont[index];
            numToIndices[oldNumber].erase(index);
            if (numToIndices[oldNumber].empty()) numToIndices.erase(oldNumber);
        }
        cont[index] = number;
        numToIndices[number].insert(index);
    }

    int find(int number) {
        return  !numToIndices[number].empty() ? *numToIndices[number].begin() : -1;
    }
};


/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */