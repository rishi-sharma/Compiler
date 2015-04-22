.data
__newline : .ascii "\n"
i1 : .word 11
.text
gcd:
addi $sp,$sp,-56
addi $t2,$sp,0
sw $fp,12($sp)
sw $ra,8($sp)
lw $t0,0($fp)
sw $t0,16($sp)
lw $t0,4($fp)
sw $t0,20($sp)
lw $t0,16($sp)
li $t1,0
slt $t2,$t0,$t1
slt $t3,$t1,$t0
or $t2,$t2,$t3
not $t2,$t2 
andi $t2,$t2,1
sw $t2,24($sp)
lw $t2,24($sp)
beqz $t2,label0
lw $fp,12($sp)
lw $ra,8($sp)
lw $v0,20($sp)
addi $sp,$fp,0
jr $ra
label0:
lw $t0,20($sp)
lw $t1,16($sp)
div $t0,$t1
mflo $t2
sw $t2,28($sp)
lw $t0,28($sp)
negu $t2,$t0
sw $t2,32($sp)
lw $t0,32($sp)
lw $t1,16($sp)
mult $t1,$t0
mflo $t2
sw $t2,36($sp)
lw $t2,36($sp)
sw $t2,40($sp)
lw $t0,20($sp)
lw $t1,40($sp)
add $t2,$t1,$t0
sw $t2,44($sp)
lw $t2,44($sp)
sw $t2,0($sp)
lw $t2,16($sp)
sw $t2,48($sp)
lw $t2,48($sp)
sw $t2,4($sp)
addi $fp,$sp,0
jal gcd
addi $t2,$v0,0
sw $t2,52($sp)
lw $fp,12($sp)
lw $ra,8($sp)
lw $v0,52($sp)
addi $sp,$fp,0
jr $ra
main:
addi $sp,$sp,-64
addi $t2,$sp,0
sw $fp,12($sp)
sw $ra,8($sp)
lw $a0,i1
li $v0,1
syscall
li $v0,4
la $a0,__newline
syscall
li $t2,10
sw $t2,16($sp)
label2:
lw $t0,16($sp)
li $t1,0
slt $t2,$t1,$t0
sw $t2,20($sp)
lw $t2,20($sp)
beqz $t2,label3
li $v0,5
syscall
sw $v0,24($sp)
li $v0,5
syscall
sw $v0,28($sp)
lw $t2,24($sp)
sw $t2,32($sp)
lw $t2,32($sp)
sw $t2,0($sp)
lw $t2,28($sp)
sw $t2,36($sp)
lw $t2,36($sp)
sw $t2,4($sp)
addi $fp,$sp,0
jal gcd
addi $t2,$v0,0
sw $t2,40($sp)
lw $t2,40($sp)
sw $t2,44($sp)
lw $a0,44($sp)
li $v0,1
syscall
li $v0,4
la $a0,__newline
syscall
lw $t0,16($sp)
li $t1,1
sub $t2,$t0,$t1
sw $t2,16($sp)
la $t2,label2
jr $t2
label3:
lw $t0,16($sp)
li $t1,0
slt $t2,$t0,$t1
slt $t3,$t1,$t0
or $t2,$t2,$t3
not $t2,$t2 
andi $t2,$t2,1
sw $t2,48($sp)
lw $t2,48($sp)
beqz $t2,label5
li $t2,1
sw $t2,52($sp)
lw $fp,12($sp)
lw $ra,8($sp)
lw $v0,52($sp)
addi $sp,$fp,0
jr $ra
la $t2,label4
jr $t2
label5:
li $t2,0
sw $t2,56($sp)
lw $fp,12($sp)
lw $ra,8($sp)
lw $v0,56($sp)
addi $sp,$fp,0
jr $ra
label4:
li $v0,10
syscall
