import re

def load_text(file):
        text = ''
        with open(file) as f:
                for line in f:
                        text += line
                return text

def get_regex_results(regex, text):
        return ''.join("%s\n"%w[1:len(w)-1] for w in re.findall(regex, text))

def main():
        file = 'function_names.txt'
        r = re.compile(r'"[\w ]+"')
        text = load_text(file)
                
        functions = get_regex_results(r, text)
        with open('parsed_{}'.format(file), 'w') as f:
                f.write(functions)

if __name__ == "__main__":
        main()
