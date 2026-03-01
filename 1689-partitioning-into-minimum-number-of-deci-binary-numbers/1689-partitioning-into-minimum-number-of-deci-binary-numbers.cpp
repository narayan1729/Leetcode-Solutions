class Solution {
public:
    int minPartitions(string n) {
        return n[max_element(n.begin(),n.end())-n.begin()]-'0';
    }
};