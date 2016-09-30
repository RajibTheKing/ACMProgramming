#include<iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
#define sq(a) ((a)*(a))
#define dist(p,q) (sq(p.x-q.x)+sq(p.y-q.y))


struct point
{
	int x, y;
};

typedef point Vector;

bool operator < (const point &a, const point &b){
	if (a.x != b.x)
		return a.x < b.x;
	return a.y < b.y;
}



Vector vec(point a, point b){
	Vector p = {b.x - a.x, b.y - a.y};
	return p;
}

int dotProd(Vector a, Vector b){
	return a.x*b.x + a.y*b.y;
}

int crossProd(Vector a, Vector b){
	return a.x*b.y - a.y*b.x;
}

bool parallel(Vector a, Vector b){
	return crossProd(a,b) == 0;
}

point points[4];
int len[4];
bool Right;

bool angleCmp(const point &a, const point &b){
	Vector n = vec(points[0], a);
	Vector m = vec(points[0], b);
	return atan2l(n.y, n.x) < atan2l(m.y, m.x);
}

int main()
{
	int t, T, i;

	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		string type;

		for (i = 0; i < 4; i++)
			scanf("%d %d", &points[i].x, &points[i].y);

		sort(points, points + 4);
		sort(points + 1, points + 4, angleCmp);

		for (i = 0; i < 4; i++)
			len[i] = dist(points[i], points[(i+1)%4]);

		Right = dotProd(vec(points[0], points[3]),vec(points[0], points[1])) == 0;

		if (len[0] == len[1] && len[1] == len[2] && len[2] == len[3]){
			if (Right)
				type = "Square";
			else
				type = "Rhombus";
		} else if (len[0] == len[2] && len[1] == len[3]){
			if (Right)
				type = "Rectangle";
			else
				type = "Parallelogram";
		} else if (parallel(vec(points[0], points[1]), vec(points[3], points[2]))
			|| parallel(vec(points[0], points[3]), vec(points[1], points[2])))
			type = "Trapezium";
		else
			type = "Ordinary Quadrilateral";

		printf("Case %d: ", t);
		cout<<type<<endl;
	}

	return 0;
}
