import re
def main():
    line = input()
    alpha_pattern = re.compile('[a-zA-Z]+')
    digit_pattern = re.compile('[0-9]+')
    other_string_pattern = re.compile('[^a-zA-Z0-9]+')
    ls = []
    while line!='0':
        while len(line) > 0:
            if alpha_pattern.match(line):
                m = alpha_pattern.match(line)
                print(m.group(),end='')
                ls = [m.group()]+ls
                line = line[m.end():]
            if digit_pattern.match(line):
                m = digit_pattern.match(line)
                idx = int(m.group())-1
                line = line[m.end():]
                s = ls[idx]
                print(s,end='')
                ls.remove(s)
                ls = [s]+ls
            if other_string_pattern.match(line):
                m = other_string_pattern.match(line)
                print(m.group(),end='')
                line = line[m.end():]
        print()
        line = input()



if __name__ == '__main__':
    main()
