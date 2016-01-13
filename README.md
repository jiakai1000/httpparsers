# httpparsers

简介：
====
http11_parser1.c : https://github.com/puma/puma/blob/master/ext%2Fpuma_http11   
http11_parser2.c : 我自己使用Ubuntu 14.04 LTS的官方仓库安装的Ragel State Machine Compiler version 6.8生成的C文件   
http_parser.c    : Node.JS的parser（源自Nginx）   

测试机器：
========
processor	: 0   
vendor_id	: GenuineIntel   
cpu family	: 6   
model		: 45   
model name	: Intel(R) Xeon(R) CPU E5-2407 0 @ 2.20GHz   
stepping	: 7   
microcode	: 0x70b   
cpu MHz		: 1200.000   
cache size	: 10240 KB   
physical id	: 0   
siblings	: 4   
core id		: 0   
cpu cores	: 4   
apicid		: 0   
initial apicid	: 0   
fpu		: yes   
fpu_exception	: yes   
cpuid level	: 13   
wp		: yes   
flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx pdpe1gb rdtscp lm constant_tsc arch_perfmon pebs bts rep_good nopl xtopology nonstop_tsc aperfmperf eagerfpu pni pclmulqdq dtes64 monitor ds_cpl vmx smx est tm2 ssse3 cx16 xtpr pdcm pcid dca sse4_1 sse4_2 x2apic popcnt tsc_deadline_timer aes xsave avx lahf_lm arat epb xsaveopt pln pts dtherm tpr_shadow vnmi flexpriority ept vpid   
bogomips	: 4389.40   
clflush size	: 64   
cache_alignment	: 64   
address sizes	: 46 bits physical, 48 bits virtual   

测试结果：
========
root@ubuntu:/opt/fastmedia/jk# time ./a.out 3000000 nginx   
text nginx 3000000   
   
real	0m4.066s   
user	0m4.066s   
sys	0m0.003s   
root@ubuntu:/opt/fastmedia/jk# time ./a.out 3000000 nginx   
text nginx 3000000   
   
real	0m4.065s   
user	0m4.065s   
sys	0m0.003s   
root@ubuntu:/opt/fastmedia/jk# time ./a.out 3000000 nginx   
text nginx 3000000   
   
real	0m4.064s   
user	0m4.064s   
sys	0m0.003s   
root@ubuntu:/opt/fastmedia/jk# time ./a.out 3000000 puma   
text puma 3000000   
   
real	0m3.215s   
user	0m3.215s   
sys	0m0.002s   
root@ubuntu:/opt/fastmedia/jk# time ./a.out 3000000 puma   
text puma 3000000   
   
real	0m3.215s   
user	0m3.215s   
sys	0m0.002s   
root@ubuntu:/opt/fastmedia/jk# time ./a.out 3000000 puma   
text puma 3000000   
   
real	0m3.217s   
user	0m3.216s   
sys	0m0.002s   
root@ubuntu:/opt/fastmedia/jk# time ./a.out 5000000 puma   
text puma 5000000   
   
real	0m5.359s   
user	0m5.359s   
sys	0m0.003s   
root@ubuntu:/opt/fastmedia/jk# time ./a.out 5000000 puma   
text puma 5000000   
   
real	0m5.361s   
user	0m5.361s   
sys	0m0.003s   
root@ubuntu:/opt/fastmedia/jk# time ./a.out 5000000 nginx   
text nginx 5000000   
   
real	0m6.780s   
user	0m6.779s   
sys	0m0.005s   
root@ubuntu:/opt/fastmedia/jk# time ./a.out 5000000 nginx   
text nginx 5000000   
   
real	0m6.778s   
user	0m6.778s   
sys	0m0.004s   
