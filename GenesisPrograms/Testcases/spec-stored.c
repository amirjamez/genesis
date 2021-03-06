begin genesis

	///Genesis comment

	global
		value numvars sample numvardist
		varlist temp[5] type(float)
		varlist foo[${numvars}] type(int)
		feature globalcomp process computation
	end
	
	program
		value numepochs sample epochdist report(1)
		feature programaccess process access
	end
	
	feature computation 
		variable dest from temp
		variable source1 from temp
		variable source2 from temp
		variable source3 from temp
		${dest} = ${source1} * ${source2} + ${source3};
	end

	feature access
		variable varj from temp report(1)
		value stride1 sample dist1 report(1)
		value stride2 sample dist1 report(1)
		value offset sample dist2 report(1)
		${varj} = arr[${stride1}*it00 + ${stride2}*it01 + ${offset}];
	end

	feature epoch
		value numcomps sample compdist report(1)
		${globalcomp}
		${programaccess}
		${programaccess}
	end


	generate 5 with dist1 = {1:10},numvardist = {2:32{*2}},epochdist = {1:5},compdist = {1:5},dist2 = {1:10}
end genesis



__kernel
void kernel_mc02_orig(unsigned int outer_tc, unsigned int inner_tc, __global __volatile float *arr){

	for (unsigned int it00 = get_local_id(0); it00 < outer_tc; it00 += get_local_size(0)) {
		for (unsigned int it01 = get_local_id(1); it01 < inner_tc; it01 += get_local_size(1)) {
            ${epoch[5]}
        }
	}
 
}
