import re

def load_text(file):
        text = ''
        with open(file) as f:
                for line in f:
                        text += line
                return text
#"%s\n"%w[1:len(w)-1]
def get_regex_results(regex, text):
        return ['{}'.format(w) for w in re.findall(regex, text) if w != None]

def main():
        file = 'function_names.txt'
        r = re.compile(r'"[\w ]+"')
        r2 = re.compile(r'[\d]+_[\d]+|[\d]+')
        text = load_text(file)
                
        functions = [w[1:len(w)-1] for w in get_regex_results(r, text)] #get results and crop "

        n_r = get_regex_results(r2, ' '.join(functions))
        n_r = [res.split('_') for res in n_r]
        output = ''.join('{};{}\n'.format(fun, ';'.join(n)) for fun,n in zip(functions, n_r))
        with open('parsed_{}'.format(file), 'w') as f:
                f.write(output)

if __name__ == "__main__":
        main()
