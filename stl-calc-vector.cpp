#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>           // fmod (remainder operator for doubles)
using namespace std;

class Calc {
private:
  vector<double> s; // s for stack

  void op(string& opCode)
  {
    if(s.size() >= 2) {
      double a = s.back(); s.pop_back();
      double b = s.back(); s.pop_back();
      double result;
           if(opCode == "+")  result = b + a;
      else if(opCode == "-")  result = b - a;
      else if(opCode == "*")  result = b * a;
      else if(opCode == "/")  result = b / a;
      else if(opCode == "%")  result = fmod(b, a);
      else {
        cout << "unknown operator " << opCode << endl;
        return;
      }
      cout << result << endl;
      s.push_back(result);
    } else
      cout << "need two numbers\n";
  }

public:
  void calc() {
    cout << "q to quit\n";

    while(true) {
      string input;
      cout << "input>";
      cin >> input;

      if(input == "q")
        break;

      double d;
      if(istringstream(input) >> d)  // use stringstream to convert string to number
        s.push_back(d);

      else if(input.size() == 1 && string("-+*/%").find(input) != string::npos)
        op(input);

      else cout << input << "<== not understood\n";

      cout << "\nstack:\n";
      print();
      cout << endl;
    }
  }
  
  void print()
  {
    // for(vector<double>::iterator it = s.begin(); it != s.end(); ++it) // C++ 98
      // cout << *it << endl;

    // for(auto it = s.begin(); it != s.end(); ++it) // auto is C++ 11
      // cout << *it << endl;

    for(auto d : s)  // range-based for is C++ 11
      cout << d << endl;
  }
};

int main(int argc, char **argv)
{
  try {
    Calc c;
    c.calc();
  } catch(const string& err) {
    cout << "caught a string err=" << err << endl;
  } catch(const char* err) {
    cout << "caught a char* err=" << err << endl;
  }
}
