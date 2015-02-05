Penum arch_t {
    noarch, i386, alpha, sparc, mips, ppc, m68k, SGI
};

Precord Pstruct entry_t {
         Pstring_SE(:"-\\d":)       name;
         '-'; Pstring_ME(:"\^\\d[\\w\\.]*":)  version;
         '-'; Pstring_ME(:"\^\\d[\\w\\.]*":)  release;
   	 '.';  arch_t      arch;
   	 ".rpm";
};

Psource Parray rpm_t {
  entry_t [];
}
