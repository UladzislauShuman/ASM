.586 
.model flat

public @Z1@8
public @Z2@8

.data
	;z1
	k dd 1.0
	two dd 2.0
	one dd 1.0
	zero dd 0
	four dd 4.0
	sum dd 0.0
	three dd 3.0
	
	;z2
	
	n dd 0.0
	deltaX dd 0.0
	xi dd 0.0
	xi1 dd 0.0
	fxi dd 0.0
	fxi1 dd 0.0
	prosto dd 0.0
	ans dd 0.0
	count dd 0
.code

@Z1@8 proc
	xor eax,eax

	finit
	fld one
	fstp k

	fld zero
	fstp sum

	cykl :
		fld k; st = k
		fmul k; st = k ^ 2
		fmul four; st = 4k ^ 2
		fld one; st = 1 4k ^ 2
		fxch; st = 4k ^ 2 1
		fsub st(0), st(1); st = 4k ^ 2 - 1 1

		fmul k; st = k * (4k ^ 2 - 1) 1
		fld one; st = 1 k * (4k ^ 2 - 1) 1
		fdiv st(0), st(1); st = 1 / (k * (4k ^ 2 - 1)) 1

		fld sum; st = sum 1 / (k * (4k ^ 2 - 1)) 1
		fadd st(0), st(1); st = (sum)+1 / (k * (4k ^ 2 - 1)) 1 / (k * (4k ^ 2 - 1)) 1
		fstp sum; st = 1 / (k * (4k ^ 2 - 1)) 1

		fstp prosto
		fstp prosto
		fstp prosto

		fld k; st = k
		fld one; st = 1 k
		fadd st(0), st(1); st = 1 + k k
		fstp k; st = k

		fstp prosto
	loop cykl

		fld sum; st = sum
		fld one; st = 1 sum
		fadd st(0),st(1); st = 1 + sum sum
		fld two; st = 2 1 + sum sum
		fxch; st = 1 + sum 2 sum
		fdiv st(0), st(1); (1 + sum) / 2 2 sum
		fstp sum; 2 sum
		
		fstp prosto
		fstp prosto
		
		xor eax,eax
		lea eax,sum
		;;;;;;;;;;;;;;;;;;;;;;;;;;;
		fldlg2
		fld sum
		fsub st(0),st(1)
		fabs
		fstp dword ptr[edx]
ret
@Z1@8 endp
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
@Z2@8 proc
mov n,ecx
mov count, ecx
finit 

fld zero
fst xi
fstp ans
	
fldpi ; st = pi
fmul two; st = 2pi  
fild n;
fxch ; st = 2pi n 
fdiv st(0),st(1); st = 2pi/n n 
fst deltaX ; detlaX = 2pi/n; st = 2pi/n n
fstp xi1 ; xi1 = 2pi/n ; st = n 

fstp prosto

cykl1:
	fld xi ; st = xi
	fmul xi; st = xi^2  
	fld xi ; st = xi xi^2
	fsin ; st = sin(xi) xi^2
	fadd ; st = sin(xi)+xi^2 xi^2
	fstp fxi; fxi = sin(xi)+xi^2 ; st = xi^2  
	
	fstp prosto

	fld xi ; st = xi 
	fld deltaX ; st = deltaX xi 
	fadd ; st = deltaX+xi xi 
	fstp xi; xi = deltaX+xi ; st = xi
	
	fstp prosto

	fld xi ; st = xi 
	fmul xi; st = xi^2
	fld xi ; st = xi xi^2
	fsin ; st = sin(xi) xi^2
	fadd ; st = sin(xi)+xi^2 xi^2
	fstp fxi1; fxi = sin(xi)+xi^2 ; st = xi^2
	
	fstp prosto
	
	fld fxi ; st = fxi
	fld fxi1 ; st = fxi1 fxi 
	fadd st(0),st(1); st = fxi1+fxi fxi 
	fld two ; st = 2 fxi1+fxi fxi 
	fxch ; st = fxi1+fxi 2 fxi 
	fdiv st(0),st(1) ; st = (fxi1+fxi)/2 2 fxi 

	fmul deltaX; st = deltaX*(fxi1+fxi)/2 2 fxi 
	fld ans ; st = ans deltaX*(fxi1+fxi)/2 2 fxi 
	fadd ; st = ans+deltaX*(fxi1+fxi)/2 deltaX*(fxi1+fxi)/2 2 fxi
	fstp ans

	fstp prosto
	fstp prosto
	fstp prosto

	fild count ; st = count
	fld one ; st = 1 count
	fxch ; st = count 1
	fsub st(0),st(1); st = count-1 1
	fist count 

	fild count 
	ficom zero
	fstsw ax
	sahf
	je _end
	
	jmp cykl1
	 
_end:
	xor eax,eax
	lea eax,ans

; посчитав интеграл мы имеем (2pi)^3/3

fld two ; st = 2
fldpi ; st = pi 2
fmul st(0),st(1) ; st = 2pi 2
fld st(0) ; st = 2pi 2pi 2
fmul st(0),st(1) ; st = (2pi)^2 2pi 2
fmul st(0),st(1) ; st = (2pi)^3 2pi 2
fld three ; st = 3 (2pi)^3 2pi 2
fxch ; st = (2pi)^3 3 2pi 2
fdiv st(0),st(1) ; st = (2pi)^3/3 3 2pi 2
fld ans; st = ans (2pi)^3/3 3 2pi 2
fsub st(0),st(1); st = ans-(2pi)^3/3 (2pi)^3/3 3 2pi 2
fabs
fstp dword ptr[edx]

ret 
@Z2@8 endp

end