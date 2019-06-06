( remind : when you call a function, its address auto add to return stack and when return, auto deleta it )
: over >r dup r> swap ; ( x y -- x y x )

( Task 1. Learn README.md )
( Task 2. Learn program, which was written above )
( Task 3. check parity )

: check_even 2 % 0 = ;

( 13 check_even - 0
  14 check_even - 1 )


( Task 4. check if x is a prime number )
: check_one 1 - if 0 else 1 then ;  ( check x == 1? -- if x == 1 to add 1 to stack else add 0 to stack )
: check_mod ( check if x % counter == 0)
	if 0 
	else ." no" 1 cr 
	then 
; 

: check 
	if ." yes" cr ( if counter == 1)
	else ( if counter > 1 ) 
		( swap dup rot swap % check_mod  )
		over % check_mod
		( counter x -- counter x counter % )
	then 
;

: check_prime
	dup check_one ( if n==1 -> no, else solve )
	if ." no" cr
	else 
 	 >r r@ 
	 repeat ( for i = n-1 -> 1 ) 
		1 - dup 
		check_one
		r@ swap check
	 until r> drop 
	then
;

( 14 check_prime -no
2 check_prime - yes
3 check_prime - yes
4 check_prime - no
5 check_prime - yes
6 check_prime - no 
7 check_prime - yes )

( Task 5. save result of any function in mem and print it ) 

: save_char ( 0/1 -- addr  save the result to memory )
    1 allot ( 0/1 addr )
    swap over ( addr 0/1 addr )
    c! ( addr )
;

: print_char ( addr -- )
    c@ .
;

: check_parity_save_and_print_result 
    check_even ( check n is even? put 0/1 to top of data stack )
    save_char ( addr )
    dup 
    print_char ."  stored at " . cr
;


( Task 6. Learn about heap)

( Task 7. )

( a )
: add_string ( s1 s2 s1.len -- s2 = s1 )
	0 ( i) for ( s1 s2 )
		2dup ( s1 s2 s1 s2 ) 
		swap ( s1 s2 s2 s1 )		
		c@ ( s1 s2 s2 s1[i] )
		swap 
		c! ( s1 s2 )	
		2inc 
	endfor
	swap drop ( s2 )
;

: concat ( s1 s2 -- s3 )
	swap	( s2 s1 because we will add s1 to s3 first, then s2 )
	2dup  count swap count ( s2 s1 s1.length s2.length )
	2dup ( .... + s1.len s2.len )
	1 + + ( .... + s3.len 1- because for null-terminated string)
	heap-alloc ( ..... + s3    -> s3 = "" )
	>r ( .... ) ( s3 )
	rot ( s2 s1.len s2.len s1 ) ( s3 )
	rot r@ ( s2 s2.len s1 s1.len s3 ) ( s3 )  
	swap ( s2 s2.len s1 s3 s1.len ) ( s3) 
	add_string ( s2 s2.len s3+s1 ) ( s3 ) 
	swap ( s2 s3+s1 s2.len ) ( s3 )
	add_string  ( s3+s1+s2 ) ( s3 )
	0 swap ( 0 s3+s1+s2 ) ( s3 ) 
	c!
	r>  
	prints
;


( m" Duc" m" Tran" concat )	
		
		
( b 
	m" Tran" string-hash 3 % . 
	0 -> Variant 0
) 
: solve_collatz ( x )
	dup	( x x )
	check_even
	if 2 / ( x/2 ) 
	else 
		3 * 
		1 + 
		( x*3 + 1)
	then 
;

: collatz
	repeat ( x )
		dup ( x x )
		check_one ( x 0/1 )
		if . 1 cr ( 1 )
		else		
			dup ( x x )
			. ( x )
			cr
			solve_collatz  
			0 ( to continue repeate )
		then
	until 
;



