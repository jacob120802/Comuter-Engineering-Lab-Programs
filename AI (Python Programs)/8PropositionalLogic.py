import itertools

def findInputs(ex):
    inputs = []
    for c in ex:
        if c != '+' and c != '*' and c != '-' and c != '(' and c != ')' and c != ' ' and c not in inputs:
            inputs.append(c)
    return inputs

def evaluate(ex, row):
    input_no = 0
    replaced = []
    for c in ex:
        if c != '+' and c != '*' and c != '-' and c != '(' and c != ')' and c != ' ' and c not in replaced:
            ex = ex.replace(c, str(row[input_no]))
            input_no += 1
            replaced.append(c)
    ex = ex.replace('+', '&')
    ex = ex.replace('*', '|')
    ex = ex.replace('-', '~')
    result = eval(ex)
    return result

def compute_results(truth_table, ex):
    outputs = []
    for row in truth_table:
        outputs.append(evaluate(ex, row))
    return outputs

n = int(input('Enter the number of inputs: '))
print('Rules:')
print('1) To enter "AND" use "+"')
print('2) To enter "OR" use "*"')
print('3) To enter "NOT" use "-"')
logical_expression = input('Enter the logical expression: ')
truth_table = list(itertools.product([0, 1], repeat=n))
table_outputs = compute_results(truth_table, logical_expression)
print('')
print('Truth Table:')
print('')
for c in findInputs(logical_expression):
    print(c, end=' ')
print('Output')
for i in range(len(truth_table)):
    for val in truth_table[i]:
        print(val, end=' ')
    print(' ', table_outputs[i])
print('')
if table_outputs.count(1) >= 1:
    print('The entered propositional logic expression is Satisfiable')
else:
    print('The entered propositional logic expression is Not Satisfiable')
