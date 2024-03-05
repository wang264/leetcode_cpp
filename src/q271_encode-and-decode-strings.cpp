#include <string>
#include <vector>

using std::vector;
using std::string;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded_string;
        
        //Iterate over each string in the input list
        for (const auto& s: strs) {
            // for each string, iterate over each character
            for (const char c: s) {
                // If the character is a slash, append an additional slash.
                if (c=='/') {
                    encoded_string += "//";
                }
                //Otherwise, simply append the character.
                else {
                    encoded_string +=c;
                }
            }
            encoded_string +="/:";
        }
        return encoded_string;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded_strings;

        string curr_string;
        for (int i=0; i<s.size(); i++) {
            // if we see "/:"
            if (i<s.size()-1 && s[i]=='/' && s[i+1]==':') {
                decoded_strings.push_back(curr_string);
                curr_string.clear();
                i++;
            }
            // if we encounter an escaped slash "//"
            else if (i<s.size()-1 && s[i]=='/' && s[i+1]=='/') {
                curr_string+='/';
                i++;
            }
            else {
                curr_string+=s[i];
            }
        }
        return decoded_strings;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));