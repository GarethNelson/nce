import os
import os.path
import sys
import posix
""" Generates a C header file which contains a single byte array containing an arbitary file
"""

filename = sys.argv[1]
if len(sys.argv) < 3: 
   out_file = filename + '.h'
else:
   out_file = sys.argv[2]

try:
   file     = open(filename,'rb')
   f_stat   = posix.fstat(file.fileno())
   length   = int(f_stat.st_size)
except Exception,e:
   print str(e)
   sys.exit(1)
print "Generating C header for %s as %s - %d bytes" %(filename,out_file,length)
varname = os.path.split(file.name)[1].replace('.','_')

header_file = open(out_file,'w')
file_data = file.read()
print str(len(file_data)) + " bytes in file"
if len(file_data) != length:
   print "WARNING! differing file lengths!"
   sys.exit(1)
header_file.write('#ifndef __%s_H_\n' % (varname,))
header_file.write('#define __%s_H_\n' % (varname,))
header_file.write('// AUTOGENERATED! Do not edit by hand!\n')
header_file.write('static unsigned int %s_len = %i;\n' %(varname,length))
header_file.write('static char embedded_%s[%i] = {' % (varname,length))
for teh_char in file_data:
    header_file.write('0x%x,' %(ord(teh_char),))
header_file.write('};\n')
header_file.write('#endif\n')
file.close()

print "Generated %s" % (out_file,)