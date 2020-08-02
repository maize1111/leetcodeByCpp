#include<bits/stdc++.h>
using namespace std;


int lengthLongestPath(string input) {
    vector<int> s;
    int indent = -1, currPos = 0, endLine = 0, maxLen = 0, currLen = 0;
    while (endLine < input.size()) {
        endLine = input.find('\n', currPos);
        if (endLine == input.npos)
            endLine = input.size();
        int currIndent = 0;
        while (input[currPos] == '\t') {
            currIndent++;
            currPos++;
        }
        // fix indent
        while (indent >= currIndent) {
            currLen -= s[s.size() - 1];
            s.pop_back();
            indent--;
        }
        indent = currIndent;
        // update current length
        s.push_back(endLine - currPos);
        currLen += endLine - currPos;
        // check if last item is a file
        if (currLen + s.size() - 1 > maxLen && input.substr(currPos, endLine - currPos).find('.') != input.npos)
            maxLen = currLen + s.size() - 1;
        currPos = endLine + 1;
    }
    return maxLen;
}
int main(){
    string path = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    cout<<lengthLongestPath(path)<<endl;
    return 0;
}