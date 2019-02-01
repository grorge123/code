struct Point {
	double x, y;
	Point (double _x = 0, double _y = 0) : x(_x), y(_y) {}
	bool operator < (const Point &rhs) const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}
};
using Vector = Point;
Point operator + (Point p, Vector v) {
	return Point(p.x + v.x, p.y + v.y);
}
Vector operator - (Point a, Point b) {
	return Vector(a.x - b.x, a.y - b.y);
}
Vector operator * (Vector v, double p) {
	return Vector(v.x * p, v.y * p);
}
Vector operator / (Vector v, double p) {
	return Vector(v.x / p, v.y / p);
}
double cross(Vector a, Vector b) {
	return a.x * b.y - a.y * b.x;
}
double dot(Vector a, Vector b) {
	return a.x * b.x + a.y * b.y;
}
int dcmp(double x) {
	return fabs(x) < 1e-10 ? 0 : x > 0 ? 1 : -1;
}
struct Line {
	Point p;
	Vector v;
	double ang;
	Line() {}
	Line(Point _p, Vector _v) : p(_p), v(_v) {
		ang = atan2(_v.y, _v.x);
	}
	bool operator < (const Line &rhs) const {
		return ang < rhs.ang;
	}
};
bool on_left(Line l, Point p) {
	return cross(l.v, p - l.p) > 0;
}
Point get_line_intersec(Line a, Line b) {
	return a.p + a.v * (cross(b.v, a.p - b.p) / cross(a.v, b.v));
}
vector<Point> half_plane_intersec(vector<Line> ls) {
	int n = ls.size();
	sort(ls.begin(), ls.end());
	int f, r;
	vector<Point> p(n), ans;
	vector<Line> q(n);
	q[f = r = 0] = ls[0];
	for (int i = 1; i < n; i++) {
		while (f < r && !on_left(ls[i], p[r - 1])) r--;
		while (f < r && !on_left(ls[i], p[f])) f++;
		q[++r] = ls[i];
		if (dcmp(cross(q[r].v, q[r - 1].v)) == 0) {
			r--;
			if (on_left(q[r], ls[i].p)) q[r] = ls[i];
		}
		if (f < r)
			p[r - 1] = get_line_intersec(q[r - 1], q[r]);
	}
	while (f < r && !on_left(q[f], p[r - 1])) r--;
	if (r - f <= 1) return ans;
	p[r] = get_line_intersec(q[r], q[f]);
	for (int i = f; i <= r; i++) ans.push_back(p[i]);
	return ans;
}
