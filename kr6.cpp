#include <iostream>
using std::cout;
using std::cin;
using std::endl;
struct CharNode {
    char c;            // сам символ
    CharNode* next;    // указатель на следующий символ
};
void untangle(CharNode* record);
void print_tangled(CharNode* record);
void print_untangled(CharNode* record);
int main()
{
    char original_record[100];
    cin >> original_record;
    CharNode tangled_record[100];
    unsigned int prev = 0;
    tangled_record[0].c = original_record[0];
    for (unsigned int i = 1; original_record[i] != '\0'; i++)
    {
        unsigned int place;
        cin >> place;
        tangled_record[place].c = original_record[i];
        tangled_record[place].next = NULL;
        tangled_record[prev].next = tangled_record + place;
        prev = place;
    }

    untangle(tangled_record);
    print_tangled(tangled_record);
    print_untangled(tangled_record);

    return 0;
}
void print_tangled(CharNode* record)
{
    while (record)
    {
        cout << record->c;
        record = record->next;
    }
    cout << endl;
}

void print_untangled(CharNode* record)
{
    while (record->next)
    {
        cout << record->c;
        record++;
    }
    cout << record->c;
    cout << endl;
}

#include <vector>
void untangle(CharNode* record) {
    std::vector<char> letters;
    for(auto current_node = record; current_node;
        current_node = current_node->next) {
        letters.push_back(current_node->c);
    }
    for(auto i = 0u; i < letters.size(); i++) {
        record[i].c = letters[i];
    }

    for(auto i = 0u; i + 1u < letters.size(); i++) {
        record[i].next = &(record[i + 1]);
    }
    record[letters.size() - 1].next = NULL;

}



