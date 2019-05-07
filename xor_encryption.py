def extract_text():
    f = open("p059_cipher.txt").read()
    f = f.split(",")
    for i in range(len(f)):
        f[i] = int(f[i])
    return f

cipher_arr = extract_text()

