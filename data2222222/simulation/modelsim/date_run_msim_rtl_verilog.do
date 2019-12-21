transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+D:/data {D:/data/date.v}
vlog -vlog01compat -work work +incdir+D:/data {D:/data/top.v}

