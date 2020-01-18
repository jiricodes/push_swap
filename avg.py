res = list()
with open("all5res") as f:
	for line in f:
		res.append(int(line))

print(sum(res)/len(res))
print(max(res))