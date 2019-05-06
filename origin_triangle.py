coordinates_global = []
origin_triangles = 0

def calc_area(t):
    return abs((t[0][0]*(t[1][1] - t[2][1]) + t[1][0]*(t[2][1] - t[0][1]) + t[2][0]*(t[0][1] - t[1][1]))/2)

def check_triangle(t):
    abc_area = calc_area(t)
    pab_area = calc_area([(0,0), t[0], t[1]])
    pbc_area = calc_area([(0,0), t[1], t[2]])
    pca_area = calc_area([(0,0), t[2], t[0]])
    if abc_area == (pab_area + pbc_area + pca_area):
        print(t, "is an origin triangle")
        return True
    else:
        print(t, "isn't an origin triangle")
        return False

def extract_cos():
    global coordinates_global
    tr_file = open("/p102_triangles.txt", 'r')
    for c in tr_file:
        cos = str(c).split(",")
        cos = [tuple([int(cos[0]), int(cos[1])]), tuple([int(cos[2]), int(cos[3])]), tuple([int(cos[4]), int(cos[5])])]
        coordinates_global.append(cos)

extract_cos()

for tr in coordinates_global:
    if check_triangle(tr):
        origin_triangles += 1

print(origin_triangles)