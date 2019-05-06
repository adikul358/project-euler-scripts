triangle_arr =[1]
words = []
top_range = 0
triangle_words = 0

def extract_words():
    global words
    tf = open("p042_words.txt").read()
    words = str(tf).split(",")
    for i in range(len(words)):
        words[i] = words[i].split('"')[1]

def word_t_no(w):
    value = 0
    for char in list(w):
        value += (ord(char) - 64)
    return value

def extract_top_range():
    global words
    global top_range
    for w in words:
        tr = word_t_no(w)
        if tr > top_range:
            top_range = tr

def generate_triangle_numbers():
    global top_range
    global triangle_arr
    n = 1
    while triangle_arr[-1] < top_range:
        triangle_arr.append(int((n*(n+1))/2))
        n+=1

extract_words()
extract_top_range()
generate_triangle_numbers()

for w in words:
    for i in triangle_arr:
        if word_t_no(w) == i:
            triangle_words += 1
            print(w, word_t_no(w))
            break
        
print(triangle_words)

# print(words)
# print(triangle_arr)
# print(top_range)