begin genesis
global
	value numepochs sample epochdist report(1)
	varlist temp[${numepochs}]
end

feature epoch
	lala;
	variable source2 from temp
end

generate 1 with epochdist = {1:4}

end genesis



__kernel
void kernel_mc02_orig(unsigned int outer_tc, unsigned int inner_tc, __global __volatile float *arr){

	for (unsigned int it00 = get_local_id(0); it00 < outer_tc; it00 += get_local_size(0)) {
		for (unsigned int it01 = get_local_id(1); it01 < inner_tc; it01 += get_local_size(1)) {
            ${epoch[5]}
        }
	}
 
}
