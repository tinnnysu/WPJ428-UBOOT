/*
 * Configuration for the Compex WPJ428
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <configs/ipq40xx_cdp.h>

#define CONFIG_MODEL_WPJ428
#define CONFIG_MODEL		"WPJ428"
#define MTDIDS_DEFAULT		"nand0=nand0"
#define MTDPARTS_DEFAULT	"mtdparts=nand0:1536k(u-boot)ro,26624k(firmware)"

#undef CONFIG_BOOTDELAY
#define CONFIG_BOOTDELAY 15

#undef CONFIG_BOOTCOMMAND
#define CONFIG_BOOTCOMMAND		"run wpjboot"

#define CONFIG_EXTRA_ENV_SETTINGS				\
	"mtdids=" MTDIDS_DEFAULT "\0"				\
	"mtdparts=" MTDPARTS_DEFAULT "\0"			\
	"nandboot=nboot firmware && bootm\0"			\
	"tftpboot=tftpsrv && bootm; sleep 5; run tftpboot\0"	\
	"wpjboot=run nandboot || run tftpboot;\0"		\

#undef V_PROMPT
#define V_PROMPT		"(" CONFIG_MODEL ") # "

#define CONFIG_SERVERIP         192.168.1.10
#define CONFIG_IPADDR		192.168.1.11
#define CONFIG_NETMASK          255.255.255.0
#define CONFIG_BOOTFILE         CONFIG_MODEL ".bin"
#define CONFIG_LZO
#define CONFIG_LZMA
#define CONFIG_SYS_LONGHELP

#define CONFIG_CMD_MISC
#define CONFIG_CMD_ELF
#define CONFIG_CMD_IMI
#define CONFIG_CMD_LOADB
#define CONFIG_CMD_SPI
#define CONFIG_CMD_TFTPSRV

#undef CONFIG_SYS_LOAD_ADDR
#define CONFIG_SYS_LOAD_ADDR    0x85000000

#undef CONFIG_SYS_TEXT_BASE
#define CONFIG_SYS_TEXT_BASE	0x84200000

#endif
