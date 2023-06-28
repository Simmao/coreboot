compile(){
gcc \
-I/home/sm/coreboot/src/include \
-I/home/sm/coreboot/src/commonlib/include \
-I/home/sm/coreboot/src/commonlib/bsd/include \
-I/home/sm/coreboot/src/soc/intel/common/block/include \
-I/home/sm/coreboot/src/soc/intel/common/pch/include \
-I/home/sm/coreboot/src/soc/intel/skylake/include \
-I/home/sm/coreboot/build \
-include /home/sm/coreboot/src/include/kconfig.h \
-x c -
}


(cat | compile) <<EOF
#include "gpio.h"
extern int printf(const char *format, ...);

int main(int argc, char *argv[]){
	int n = ARRAY_SIZE(gpio_table);
	for(int i=0; i<n; i++){
		const struct pad_config *cfg = &gpio_table[i];
		printf("%d: 0x%08X, 0x%08X\n", i, cfg->pad_config[0], cfg->pad_config[1]);
	}
	return 0;
}

EOF
