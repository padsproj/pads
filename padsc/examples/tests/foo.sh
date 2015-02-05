#!/bin/sh

if [ ! -e /Users/kfisher/pads/scripts/padsc  ]; then echo "UNEXPECTED: /Users/kfisher/pads/scripts/padsc  not found"; exit 1; fi
if [ ! -e "/Users/kfisher/pads/lib/padsc.ARCH=x86; OPSYS=darwin; HEAP_SUFFIX=x86-darwin" ]; then echo "UNEXPECTED: padsc compiler obj /Users/kfisher/pads/lib/padsc.ARCH=x86; OPSYS=darwin; HEAP_SUFFIX=x86-darwin not found"; echo "     Have you built the PADS compiler?"; echo "     Try: using 'gmake' in the top-level padsc directory."; exit 1; fi
if [ ! -e /Users/kfisher/pads/ast-ast/arch/darwin.i386/lib/libpads-g.a ]; then echo "UNEXPECTED: library /Users/kfisher/pads/ast-ast/arch/darwin.i386/lib/libpads-g.a does not exist"; exit 1; fi
if [ ! -e /Users/kfisher/pads/ast-ast/arch/darwin.i386/lib/libast.a ]; then echo "UNEXPECTED: library /Users/kfisher/pads/ast-ast/arch/darwin.i386/lib/libast.a does not exist"; exit 1; fi
if [ ! -e /Users/kfisher/pads/ast-ast/arch/darwin.i386/lib/libpads.a ]; then echo "UNEXPECTED: library /Users/kfisher/pads/ast-ast/arch/darwin.i386/lib/libpads.a does not exist"; exit 1; fi
if [ ! -e /Users/kfisher/pads/ast-ast/arch/darwin.i386/lib/libast.a ]; then echo "UNEXPECTED: library /Users/kfisher/pads/ast-ast/arch/darwin.i386/lib/libast.a does not exist"; exit 1; fi
