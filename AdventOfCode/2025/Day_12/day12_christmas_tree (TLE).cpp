#include <bits/stdc++.h>
using namespace std;

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


class Shape
{
public:
    vector<string> pattern;
    int width, height;

    Shape(const vector<string>& p) : pattern(p)
    {
        height = p.size();
        width = p[0].size();
    }

    Shape() : width(0), height(0) {}  // Default constructor

    // Rotate 90 degrees clockwise
    Shape rotate() const {
        vector<string> rotated(width, string(height, '.'));
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                rotated[j][height - 1 - i] = pattern[i][j];
            }
        }
        return Shape(rotated);
    }

    // Flip horizontally
    Shape flip() const {
        vector<string> flipped = pattern;
        for (string& row : flipped) {
            reverse(row.begin(), row.end());
        }
        return Shape(flipped);
    }

    bool operator<(const Shape& other) const {
        if (height != other.height) return height < other.height;
        if (width != other.width) return width < other.width;
        return pattern < other.pattern;
    }
};

class Solver {
private:
    vector<Shape> shapes;
    vector<vector<Shape>> shapeVariants;
    int gridWidth, gridHeight;
    vector<int> requiredCounts;
    vector<vector<char>> grid;

public:
    Solver(const vector<Shape>& s, int w, int h, const vector<int>& counts)
        : shapes(s), gridWidth(w), gridHeight(h), requiredCounts(counts) {
        generateAllVariants();
    }

private:
    void generateAllVariants() {
        shapeVariants.resize(shapes.size());

        for (int i = 0; i < shapes.size(); i++) {
            set<Shape> uniqueVariants;

            // Generate all rotations
            Shape current = shapes[i];
            for (int rot = 0; rot < 4; rot++) {
                uniqueVariants.insert(current);
                current = current.rotate();
            }

            // Generate all rotations of flipped shape
            current = shapes[i].flip();
            for (int rot = 0; rot < 4; rot++) {
                uniqueVariants.insert(current);
                current = current.rotate();
            }

            // Convert set to vector
            for (const auto& variant : uniqueVariants) {
                shapeVariants[i].push_back(variant);
            }
        }
    }

    bool canPlace(const Shape& shape, int x, int y) {
        if (x + shape.width > gridWidth || y + shape.height > gridHeight) {
            return false;
        }

        for (int i = 0; i < shape.height; i++) {
            for (int j = 0; j < shape.width; j++) {
                if (shape.pattern[i][j] == '#' && grid[y + i][x + j] != '.') {
                    return false;
                }
            }
        }
        return true;
    }

    void placeShape(const Shape& shape, int x, int y, char marker) {
        for (int i = 0; i < shape.height; i++) {
            for (int j = 0; j < shape.width; j++) {
                if (shape.pattern[i][j] == '#') {
                    grid[y + i][x + j] = marker;
                }
            }
        }
    }

    void removeShape(const Shape& shape, int x, int y) {
        for (int i = 0; i < shape.height; i++) {
            for (int j = 0; j < shape.width; j++) {
                if (shape.pattern[i][j] == '#') {
                    grid[y + i][x + j] = '.';
                }
            }
        }
    }

    bool backtrack(int shapeIndex, vector<int>& remaining) {
        // If all shapes placed
        if (shapeIndex == shapes.size()) {
            return true;
        }

        // If no more of this shape needed, move to next
        if (remaining[shapeIndex] == 0) {
            return backtrack(shapeIndex + 1, remaining);
        }

        // Try to place current shape at all possible positions
        for (int y = 0; y < gridHeight; y++) {
            for (int x = 0; x < gridWidth; x++) {
                // Try all variants of current shape
                for (const Shape& variant : shapeVariants[shapeIndex]) {
                    if (canPlace(variant, x, y)) {
                        placeShape(variant, x, y, 'A' + shapeIndex);
                        remaining[shapeIndex]--;

                        if (backtrack(shapeIndex, remaining)) {
                            return true;
                        }

                        // Backtrack
                        removeShape(variant, x, y);
                        remaining[shapeIndex]++;
                    }
                }
            }
        }

        return false;
    }

public:
    bool canFit() {
        // Initialize grid
        grid.assign(gridHeight, vector<char>(gridWidth, '.'));

        // Create a copy of required counts
        vector<int> remaining = requiredCounts;

        // Try all shapes
        return backtrack(0, remaining);
    }
};

int main()
{
    ifstream input("input.txt");
    string line;
    getline(input, line);
    int testCases = stoi(line);
    vector<Shape> shapes;
    int result = 0;
    for (int kase = 1; kase <= testCases; ++kase)
    {
        shapes.clear();
        result = 0;
        for (int shapeIdx = 0; shapeIdx < 6; shapeIdx++)
        {
            vector<string> shapesInput;
            while(getline(input, line) && !line.empty())
            {
                if (line.find(":") != string::npos) continue;
                shapesInput.push_back(line);
                cout << "Shape line: " << line << endl;
            }
            cout << "Read shape with " << shapesInput.size() << " lines." << endl;
            shapes.push_back(Shape(shapesInput));
        }

        vector<int> required(shapes.size(), 0);

        while(getline(input, line) && !line.empty())
        {
            cout << "Line: " << line << endl;
            vector<string> parts = split(line, ' ');
            size_t xPos = parts[0].find('x');
            size_t colonPos = parts[0].find(':');

            int width = stoi(parts[0].substr(0, xPos));
            int height = stoi(parts[0].substr(xPos + 1, colonPos - xPos - 1));
            for (int i = 0; i < shapes.size(); i++)
            {
                required[i] = stoi(parts[i + 1]);
            }

            Solver solver(shapes, width, height, required);
            if (solver.canFit()) {
                result++;
            }
        }
        cout << "Kase " << kase << ": " <<  result << endl;
    }
}