#include <iostream>
#include <ctime>
#include <string>

using namespace std;
void pause(int dur);
string extend(string a);

int main(void)
{
	string a = " ";

	for (int i = 0; i < 4; i++)
	{
		system("clear");
		cout << "Riverbank A       Riverbank B" << endl << endl;
		cout << a << "     /|" << endl;
		cout << a << "    / |" << endl;
		cout << a << "   /__|" << endl;
		cout << a << "______|______" << endl;
		cout << a << "\\           /" << endl;
		cout << a << " \\_________/" << endl;
		pause(1);
		a = extend(a);
	}

	return 0;
}

void pause(int dur)
{
    int temp = time(NULL) + dur;
    
    while(temp > time(NULL));
}

string extend(string a)
{
	a.append("     ");
	return a;
}
