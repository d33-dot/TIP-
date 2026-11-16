#include <iostream>
#include <string>
#include <stack>
using namespace std;

// задача 1
// int main() {
//     string s;
//     getline(cin, s);          // важно: getline, а не cin >>, иначе читаем только до пробела

//     stack<char> st;
//     bool ok = true;

//     for (char c : s) {
//         if (c == '(' || c == '[' || c == '{') {
//             st.push(c);                     // открывающая — ждёт свою пару
//         } else if (c == ')' || c == ']' || c == '}') {
//             if (st.empty()) { ok = false; break; }   // закрывать нечего
//             char open = st.top();
//             st.pop();
//             // проверяем, что типы совпали
//             if ((c == ')' && open != '(') ||
//                 (c == ']' && open != '[') ||
//                 (c == '}' && open != '{')) {
//                 ok = false;
//                 break;
//             }
//         }
//         // все остальные символы (буквы, пробелы, '?', ')' в тексте и т.п.) просто пропускаем
//     }

//     if (!st.empty()) ok = false;            // остались незакрытые

//     cout << (ok ? "yes" : "no") << endl;
//     return 0;
// }

#include <vector>
#include <set>

// задание 2
// bool isWordByte(unsigned char c) {
//     if (c >= 0x80) return true;                 // байт кириллицы в UTF-8
//     if (c == '-')  return true;                 // дефис внутри слова: всё-таки
//     if (c >= '0' && c <= '9') return true;
//     if (c >= 'a' && c <= 'z') return true;
//     if (c >= 'A' && c <= 'Z') return true;
//     return false;                               // остальное — разделитель
// }

// string toLower(const string& w) {
//     string r = w;
//     for (size_t i = 0; i < r.size(); ++i) {
//         unsigned char c = r[i];
//         if (c >= 'A' && c <= 'Z') {
//             r[i] = c - 'A' + 'a';               // латиница
//         } else if (c == 0xD0 && i + 1 < r.size()) {
//             unsigned char n = r[i + 1];
//             if (n >= 0x90 && n <= 0x9F) {        // А-П
//                 r[i + 1] = n + 0x20;
//                 ++i;
//             } else if (n == 0x81) {              // Ё
//                 r[i] = 0xD1; r[i + 1] = 0x91;
//                 ++i;
//             } else if (n >= 0xA0 && n <= 0xAF) { // Р-Я
//                 r[i] = 0xD1; r[i + 1] = n - 0x20;
//                 ++i;
//             }
//         }
//     }
//     return r;
// }

// int main() {
//     string s;
//     getline(cin, s);

//     set<string> seen;        // уже встречавшиеся слова (в нижнем регистре)
//     vector<string> order;    // порядок первого появления
//     string cur;              // текущее накапливаемое слово

//     for (size_t i = 0; i <= s.size(); ++i) {
//         char c = (i < s.size()) ? s[i] : ' ';    // ' ' в конце — «толчок», чтобы сбросить последнее слово
//         if (isWordByte((unsigned char)c)) {
//             cur += c;
//         } else if (!cur.empty()) {
//             string low = toLower(cur);
//             if (seen.insert(low).second)         // insert возвращает {итератор, был ли новый}
//                 order.push_back(low);
//             cur.clear();
//         }
//     }

//     for (const string& w : order)
//         cout << w << '\n';

//     return 0;
// }

// задание 3
// class MinStack {
// private:
//     vector<int> data;   // сами элементы стека
//     vector<int> mins;   // mins[i] = минимум среди data[0..i]

// public:
//     void push(int x) {
//         data.push_back(x);
//         mins.push_back(mins.empty() ? x : min(x, mins.back()));
//     }

//     void pop() {
//         if (data.empty()) return;   // защита от pop на пустом стеке
//         data.pop_back();
//         mins.pop_back();
//     }

//     bool empty() const { return data.empty(); }

//     int top() const { return data.back(); }

//     int getMin() const { return mins.back(); }   // O(1)!
// };

// int main() {
//     MinStack st;
//     string cmd;
//     while (cin >> cmd) {
//         if (cmd == "push") {
//             int x; cin >> x;
//             st.push(x);
//         } else if (cmd == "pop") {
//             st.pop();
//         } else if (cmd == "empty") {
//             cout << (st.empty() ? "true" : "false") << '\n';
//         } else if (cmd == "top") {
//             if (!st.empty()) cout << st.top() << '\n';
//         } else if (cmd == "min") {
//             if (!st.empty()) cout << st.getMin() << '\n';
//         }
//     }
//     return 0;
// }