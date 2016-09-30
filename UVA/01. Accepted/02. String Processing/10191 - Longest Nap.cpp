#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define MAXSIZE (100 + 2)

struct time_format
{
	string time;
	int start;
	int end;
};

bool cmp(time_format x, time_format y)
{
	if (x.start != y.start)
		return x.start < y.start;
	return x.end < y.end;
}

void reset(time_format t[])
{
    t[0].time = "10:00";
	t[0].start = 600;
	t[0].end = 600;

	t[1].time = "18:00";
	t[1].start = 1080;
	t[1].end = 1080;
}

int main()
{
	time_format t[MAXSIZE];
	int cases = 0;
	int events;
	string line;

	while (cin >> events)
	{
	    cases++;
		cin.ignore();
		int counter = 2;

		reset(t);

		while ((counter - 2) < events)
		{
			getline(cin, line);

			t[counter].start = atoi(line.substr(0, 2).data()) * 60;
			t[counter].start += atoi(line.substr(3, 2).data());
			t[counter].end = atoi(line.substr(6, 2).data()) * 60;
			t[counter].end += atoi(line.substr(9, 2).data());
			t[counter].time = line.substr(6, 5);

			counter++;
		}


		sort(t, t + events + 2, cmp);
		int longest_nap = 0;
		string longest_start;

		for (int i = 0; i < events + 1; i++)
			if ((t[i + 1].start - t[i].end) > longest_nap)
			{
				longest_start = t[i].time;
				longest_nap = t[i + 1].start - t[i].end;
			}


		cout << "Day #" << cases << ": the longest nap starts at ";
		cout << longest_start << " and will last for ";
		if (longest_nap < 60)
			cout << longest_nap;
		else
			cout << (longest_nap / 60) << " hours and " << (longest_nap % 60);
		cout << " minutes.\n";
	}

	return 0;
}
