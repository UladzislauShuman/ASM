.586 
.model flat

public @zad1@8
public @zad2@8
public @zad3@8

.data
	one dd 1.0
	res dd 0.0
.code

@zad1@8 proc
finit 

fld dword ptr[ecx]; st = x
fmul st(0),st(0) ; st = x^2
fld dword ptr[ecx]; st = x x^2
fdiv dword ptr[edx]; st = x/y x^2
fptan ; st = 1 tan(x/y) x^2

fld dword ptr[edx]; st = y 1 tan(x/y) x^2
fmul st(0),st(0) ;st = y^2 1 tan(x/y) x^2

fld st(3); st = x^2 y^2 1 tan(x/y) x^2
fmul st(0), st(3) ;st = x^2*tan(x/y) y^2 1 tan(x/y) x^2
fld st(1);y^2 x^2*tan(x/y) y^2 1 tan(x/y) x^2
fdiv st(0),st(4); ;y^2/tan(x/y) x^2*tan(x/y) y^2 tan(x/y) x^2
fadd st(0),st(1);st =y^2/tan(x/y)+x^2*tan(x/y) x^2*tan(x/y) y^2 tan(x/y) x^2

fstp res
lea eax,res

ret
@zad1@8 endp

@zad2@8 proc
finit 

fld dword ptr[edx]; st = y
fld dword ptr[ecx]; st = x y
fyl2x; st = log2(x) * y
		
fld dword ptr[edx]; st = y y * log2(x)
fmul dword ptr[ecx]; st = xy y * log2(x)
fadd st(0), st(1); st = xy + y * log2(x) y * log2(x)

fld dword ptr[ecx]; st = x xy + y * log2(x) y * log2(x)
fdiv dword ptr[edx]; st = x / y xy + y * log2(x) y * log2(x)
fld one; st = 1 x / y xy + y * log2(x) y * log2(x)
fpatan; st = atan(-x / y) xy + y * log2(x) y * log2(x)
fdiv

fstp res
lea eax,res

ret
@zad2@8 endp

@zad3@8 proc
finit 

fld dword ptr[ecx]; st = x
fsub dword ptr[edx]; st = x - y
fabs; st = | x - y |

fld dword ptr[ecx]; st = x | x - y |
fdiv dword ptr[edx]; st = x / y | x - y |

fld dword ptr[edx]; st = y x / y | x - y |
fdiv dword ptr[ecx]; st = y / x x / y | x - y |

fadd st(0), st(1); st = y / x + x / y   x / y | x - y |
fcos; st = cos(y / x + x / y)   x / y | x - y |
fmul st(0),st(2); st = cos(y / x + x / y)*| x - y |   x / y   | x - y |

fstp res
lea eax,res
ret
@zad3@8 endp

end