    .source Main.j
    .class public Main
    .super java/lang/Object
    .method public static calculate_pi(I)F
    .limit stack 500
    .limit locals 500
    ldc 3.000000
    fstore 1
    ldc 2.000000
    fstore 2
    iconst_1
    istore 3
        ldc 1
        istore 4
        for0:
        iload 4
        iload 0
        if_icmplt LESLabel0
        iconst_0
        goto LESend0
        LESLabel0:
        iconst_1
        LESend0:
        ifne forstmt0
        goto forEnd0
        forAddAdd0:
        iload 4
        iconst_1
        iadd
        istore 4
        goto for0
        forstmt0:
        ldc 4
        i2f
        fload 2
        iload 4
        i2f
        fmul
        fload 2
        iload 4
        i2f
        fmul
        ldc 1.000000
        fadd
        fmul
        fload 2
        iload 4
        i2f
        fmul
        fload 2
        fadd
        fmul
        fdiv
        fstore 5
        iload 3
        dup
        istore 100
        ifeq ifEnd0
        if0:
            fload 1
            fload 5
            fadd
            fstore 1
            iload 3
            iconst_0
            istore 3
            pop
            ifEnd0:
        iload 100
        ifne elseEnd1
            fload 1
            fload 5
            fsub
            fstore 1
            iload 3
            iconst_1
            istore 3
            pop
            elseEnd1:
    goto forAddAdd0
    forEnd0:
    fload 1
    freturn
    .end method
    .method public static main([Ljava/lang/String;)V
    .limit stack 500
    .limit locals 500
    ldc 100
    istore 7
    iload 7
    invokestatic Main/calculate_pi(I)F
    fstore 8
    getstatic java/lang/System/out Ljava/io/PrintStream;
    ldc "Approximation of Pi after "
    invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
    getstatic java/lang/System/out Ljava/io/PrintStream;
    iload 7
    invokevirtual java/io/PrintStream/print(I)V
    getstatic java/lang/System/out Ljava/io/PrintStream;
    ldc " terms: "
    invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
    getstatic java/lang/System/out Ljava/io/PrintStream;
    fload 8
    invokevirtual java/io/PrintStream/print(F)V
    getstatic java/lang/System/out Ljava/io/PrintStream;
    invokevirtual java/io/PrintStream/println()V
    ldc 0
    return
    .end method
