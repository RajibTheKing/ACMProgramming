with open("input.txt", "r") as f:
    lines = f.readlines()

pos = [tuple(map(int, line.split(","))) for line in lines]
n = len(pos)

def get_area(i, j):
    return (abs(pos[i][0] - pos[j][0]) + 1) * (abs(pos[i][1] - pos[j][1]) + 1)

def rect_is_inside_poly(i, j):
    x_l = min(pos[i][0], pos[j][0])
    x_r = max(pos[i][0], pos[j][0])
    y_t = min(pos[i][1], pos[j][1])
    y_b = max(pos[i][1], pos[j][1])
    for k in range(n):
        p, q = pos[k], pos[(k+1)%n]
        #if x_l < q[0] and q[0] < x_r and y_t < q[1] and q[1] < y_b:
        #    return False
        if p[0] == q[0]:
            y1 = min(p[1], q[1])
            y2 = max(p[1], q[1])
            if x_l < q[0] and q[0] < x_r and not (y2 <= y_t or y1 >= y_b):
                return False
        else:
            x1 = min(p[0], q[0])
            x2 = max(p[0], q[0])
            if y_t < q[1] and q[1] < y_b and not (x2 <= x_l or x1 >= x_r):
                return False
    return True

res = 0
for i, j in ((i, j) for i in range(n) for j in range(i+1, n)):
    if rect_is_inside_poly(i, j):
        res = max(res, get_area(i, j))
print(res)