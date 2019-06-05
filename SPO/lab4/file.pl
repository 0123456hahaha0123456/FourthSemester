$var = "abc14,7asdf";
if ($var =~ /\,/ ){
	$ok = 1;
	$var =~ s/\,/\./;
}
else{
	$ok = 0;
}
		
if ($var =~ s/(\d+\.?\d+)/$1*2/e){
	print "Hello world ! \n" ;
	if ($ok =~ /0/ ) {print $var;}
	else {
		$var =~ s/\./\,/;
		print $var;
	}
	print "\n";
}



