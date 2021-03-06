/* Mode: -*- C++ -*- */
/* @BC
 *		                Copyright (c) 1993
 *	    by Microelectronics and Computer Technology Corporation (MCC)
 *				All Rights Reserved
 *
 *	Permission to use, copy, modify, and distribute this software and its
 *	documentation for any purpose and without fee is hereby granted,
 *	provided that this notice be retained unaltered, and that the name of
 *	MCC and its shareholders and participants shall not be used in
 *	advertising or publicity pertaining to distribution of the software
 *	without specific written prior permission.
 *
 *	THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 *	IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 *	WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/*
 * $Header$
 *
 * $Log$
 *
 @EC */

#if !defined(_RBL_Atom_h)
#define _RBL_Atom_h

#ifdef __GNUG__
#pragma interface
#endif

#include "rosette.h"

#include "Ob.h"

class RblAtom : public Ob
{
  protected:

    Ob*		atom;

    RblAtom (int, Ob*, Ob*);

    friend Ob*	decodeAtom (Ob*);

  public:

    virtual Ob*	self ();
    virtual Ob*	cloneTo (Ob*, Ob*);
    virtual Ob*	update (bool, Ctxt*);
    virtual pOb primitiveInitialize (pCtxt);
    virtual bool coversp (pOb);
};


class Symbol : public RblAtom
{
    STD_DECLS(Symbol);

  protected:

    Symbol ();

  public:

    static Symbol*	create ();

    bool	ConstantP ();
    void	printOn (FILE*);
    void	printQuotedOn (FILE*);
    void	displayOn (FILE*);
    const char*	asCstring ();
    char*	asPathname ();
    Pattern*	makePattern ();
    AttrNode*	makeAttrNode (bool valueCtxt);
    Ob*		unquote ();
};


class RblBool : public RblAtom
{
    STD_DECLS(RblBool);

  protected:

    RblBool ();

  public:

    static RblBool*	create ();
    const char*		asCstring ();

    virtual convertArgReturnPair  convertActualArg(Ctxt*, Ob*);
    //virtual Ob*         convertActualRslt(Ctxt*, Word32);
};

class Char : public RblAtom
{
    STD_DECLS(Char);

  protected:

    Char ();

  public:

    static Char*	create ();
    void		printOn (FILE*);
    void		displayOn (FILE*);
    char*		asCstring ();
};


static const int FixnumFormatSize = 16;

class Fixnum : public RblAtom
{
    STD_DECLS(Fixnum);

  protected:

    Fixnum ();

    static char format [FixnumFormatSize];
    friend BUILTIN_PRIM(fxFormat);

  public:

    static Fixnum*	create ();
    char* 		asCstring ();

    virtual convertArgReturnPair  convertActualArg(Ctxt*, Ob*);
    virtual Ob* convertActualRslt(Ctxt*, Word32);
};


class Niv : public RblAtom
{
    STD_DECLS(Niv);

  protected:

    Niv ();

  public:

    static Niv*	create ();
    char*	asCstring ();
    Ob*		invoke (Ctxt*);
};


class Sysval : public RblAtom
{
    STD_DECLS(Sysval);

  protected:

    Sysval ();

  public:

    static Sysval*	create ();
    char*		asCstring ();
};


class ExpandedLocation : public RblAtom
{
    STD_DECLS(ExpandedLocation);

  protected:

    ExpandedLocation ();

  public:

    static ExpandedLocation*	create ();
    char*			asCstring ();
};

#endif
