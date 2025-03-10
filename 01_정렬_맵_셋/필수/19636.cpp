#include <iostream>
#include <cmath>
using namespace std;

void notChange(int weight, int meta, int activity, int intake, int days) {
    for (int i = 0; i < days; i++) {
        int change = intake - (meta + activity);
        weight += change;

        if (weight <= 0) {
            cout << "Danger Diet\n";
            return;
        }
    }
    cout << weight << " " << meta << '\n';
}

void change(int weight, int meta, int activity, int intake, int days, int thre) {
    int currentWeight = weight;
    int currentMeta = meta;

    for (int i = 0; i < days; i++) {
        int out = currentMeta + activity;
        int change = intake - out;
        currentWeight += change;

        if (abs(change) > thre) {
            if (change > 0) {
                currentMeta += change / 2;
            }
            else {
                currentMeta += (change - 1) / 2;
            }
        }

        if (currentWeight <= 0 || currentMeta <= 0) {
            cout << "Danger Diet\n";
            return;
        }
    }

    cout << currentWeight << " " << currentMeta << " ";
    cout << ((meta > currentMeta) ? "YOYO" : "NO") << '\n';
}

int main() {
    int weight, meta, thre, days, intake, activity;
    cin >> weight >> meta >> thre;
    cin >> days >> intake >> activity;

    notChange(weight, meta, activity, intake, days);
    change(weight, meta, activity, intake, days, thre);

    return 0;
}