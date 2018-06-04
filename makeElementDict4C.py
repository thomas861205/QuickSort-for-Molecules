f = open("PeriodicTableV2.txt", 'r')
content = f.read().split()
f.close()

dump = open("PeriodicTable4C.cpp", "w")

def foo1():
	for word in content:
	    # print(word)
	    if word[0] >= 'A' and word[0] <= 'z':
	        dump.write("    {\"" + word + "\", ")
	    elif word[0] >= '0' and word[0] <= '9':
	    	dump.write(word + "},\n")

def foo2():
	for word in content:
	    # print(word)
	    if word[0] >= 'A' and word[0] <= 'z':
	        dump.write("	elementTable[\"" + word + "\"] = ")
	    elif word[0] >= '0' and word[0] <= '9':
	    	dump.write(word + ";\n")
foo2()
dump.close()