class Point3D
{
public:
    double x, y, z;

    Point3D(double x_val = 0, double y_val = 0, double z_val = 0)
        : x(x_val), y(y_val), z(z_val) {}
};

class DSU
{
public:
    DSU(int n) : parent(n), sz(n, 1)
    {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int a)
    {
        if (parent[a] != a)
            parent[a] = find(parent[a]);
        return parent[a];
    }

    void unite(int a, int b)
    {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB)
        {
            if (sz[rootA] < sz[rootB])
            {
                parent[rootA] = rootB;
            }
            else if (sz[rootA] > sz[rootB])
            {
                parent[rootB] = rootA;
            }
            else
            {
                parent[rootB] = rootA;
            }

            total = sz[rootA] + sz[rootB];
            sz[rootA] = total;
            sz[rootB] = total;
        }
    }

    void print_sizes()
    {
        for (int i = 0; i < parent.size(); ++i)
        {
            cout << "Element: " << i << ", Parent: " << parent[i] << ", Size: " << sz[i] << endl;
        }
    }

    vector<long long> get_top_3_sizes()
    {
        vector<long long> sizes;
        set<int> unique_parents;
        for (int i = 0; i < parent.size(); ++i)
        {
            int root = find(i);
            if (unique_parents.find(root) == unique_parents.end())
            {
                unique_parents.insert(root);
                sizes.push_back(sz[root]);
            }
        }

        // Descent sort and get top 3
        sort(sizes.begin(), sizes.end(), greater<long long>());

        if (sizes.size() > 3)
            sizes.resize(3);
        return sizes;
    }

private:
    vector<int> parent;
    vector<int> sz;
    int total;
};

vector<string> split(const string& s, char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

long long sq(long long val)
{
    return val * val;
}

long long get_distance(Point3D p1, Point3D p2)
{
    return sq(p1.x - p2.x) + sq(p1.y - p2.y) + sq(p1.z - p2.z);
}

bool compare_distance(const array<long long, 3>& a, const array<long long, 3>& b)
{
    return a[0] < b[0];
}

long long solve_part2(const vector<Point3D>& points)
{
    long long result = 1;
    vector<array<long long, 3> > distances;

    for (int i = 0; i< points.size(); ++i)
    {
        for (int j = i + 1; j < points.size(); ++j)
        {
            long long dist = get_distance(points[i], points[j]);
            distances.push_back({dist, i, j});
        }
    }
    sort(distances.begin(), distances.end(), compare_distance);
    DSU dsu(points.size());

    for (int i = 0; i < distances.size(); ++i)
    {
        int idx1 = distances[i][1];
        int idx2 = distances[i][2];

        if (dsu.find(idx1) != dsu.find(idx2))
        {
            dsu.unite(idx1, idx2);
            vector<long long> top_sizes = dsu.get_top_3_sizes();
            if (top_sizes.size() == 1)
            {
                // All in one circuit! This is the last connection
                long long result = (long long)points[idx1].x * (long long)points[idx2].x;
                cout << "X coordinates: " << points[idx1].x << " * " << points[idx2].x << " = " << result << endl;
                return result;
            }
        }
    }
    return result;
}