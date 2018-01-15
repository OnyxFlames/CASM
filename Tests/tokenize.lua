io.write("Running test 'tokenize.lua'\n")
os.execute("mkdir Output && rm Output/tokenize.txt")
os.execute("casm ../Tests/tokenize.casm --tokenize >> Output/tokenize.txt")
io.write("Output written to Output/tokenize.txt")