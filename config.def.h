/*             See LICENSE file for copyright and license details.            */
/*====================================DWM=====================================*/
/*  DWM appearance settings                                                   */
static int gapsforone               = 0; /* Gaps for only one window open     */
static int hidevactags              = 0; /* Hide vacant tags                  */
static const int showbar            = 1; /* 0 means no bar                    */
static const int topbar             = 1; /* 0 means bottom bar                */
static const int barheight          = 26;/* Specific bar height (0 for def)   */
static const int startontag         = 1; /* 0 means no tag is active on start */
static const unsigned int igappx    = 5; /* Size of inner gaps                */
static const unsigned int ogappx    = 5; /* Size of outer gaps                */
static const unsigned int snap      = 32;/* Snap pixel                        */
static const unsigned int borderpx  = 1; /* Border pixel of windows           */
static const char *fonts[]          = { "FreeMono:size=12", /* Primary        */
                                        "FreeSerif:size=12", /* Secondary     */
                                        "FontAwesome:size=10" }; /* Iconic    */
/*  DWM color scheme                                                          */
static const char ltsymfgsel[]      = "#eeeeee"; /* Layout symbol selected fg */
static const char ltsymbgsel[]      = "#005577"; /* Layout symbol selected bg */
static const char ltsymfgnrm[]      = "#bbbbbb"; /* Layout symbol normal fg   */
static const char ltsymbgnrm[]      = "#222222"; /* Layout symbol normal bg   */
static const char tlbrdrsel[]       = "#444444"; /* Tiled border selected     */
static const char flbrdrsel[]       = "#005577"; /* Floating border selected  */
static const char tlbrdrnrm[]       = "#444444"; /* Tiled border normal       */
static const char flbrdrnrm[]       = "#444444"; /* Floating border normal    */
static const char statfgsel[]       = "#bbbbbb"; /* Status bar selected fg    */
static const char statbgsel[]       = "#005577"; /* Status bar selected bg    */
static const char statfgnorm[]      = "#bbbbbb"; /* Status bar normal fg      */
static const char statbgnorm[]      = "#222222"; /* Status bar normal bg      */
static const char tagsselfg[]       = "#eeeeee"; /* Tags selected fg          */
static const char tagsselbg[]       = "#005577"; /* Tags selected bg          */
static const char tagsnormfg[]      = "#bbbbbb"; /* Tags normal fg            */
static const char tagsnormbg[]      = "#222222"; /* Tags normal bg            */
static const char infoselfg[]       = "#eeeeee"; /* Client info selected fg   */
static const char infoselbg[]       = "#005577"; /* Client info selected bg   */
static const char infonormfg[]      = "#bbbbbb"; /* Client info normal fg     */
static const char infonormbg[]      = "#222222"; /* Client info normal bg     */
static const char unusedcol[]       = "#000000"; /* Placeholder for the array */
static const char *colors[][4]      = {
/*  Scheme                     Foreground, Background, Tileborder, Fltborder  */
    [SchemeSel]            = { ltsymfgsel, ltsymbgsel, tlbrdrsel,  flbrdrsel  },
    [SchemeNorm]           = { ltsymfgnrm, ltsymbgnrm, tlbrdrnrm,  flbrdrnrm  },
    [SchemeStatusSel]      = { statfgsel,  statbgsel,  unusedcol,  unusedcol  },
    [SchemeStatusNorm]     = { statfgnorm, statbgnorm, unusedcol,  unusedcol  },
    [SchemeTagsSel]        = { tagsselfg,  tagsselbg,  unusedcol,  unusedcol  },
    [SchemeTagsNorm]       = { tagsnormfg, tagsnormbg, unusedcol,  unusedcol  },
    [SchemeInfoSel]        = { infoselfg,  infoselbg,  unusedcol,  unusedcol  },
    [SchemeInfoNorm]       = { infonormfg, infonormbg, unusedcol,  unusedcol  },
};
/*  DWM Alpha scheme                                                          */
static const unsigned int barfgalpha       = 0xffU; /* Opaque foreground      */
static const unsigned int barbgalpha       = 0xd0;  /* Transparent background */
static const unsigned int tlbrdralpha      = 0xffU; /* Opaque tiled border    */
static const unsigned int flbrdralpha      = 0xffU; /* Opaque floating border */
static const unsigned int alphas[][4]      = {
/*  Scheme                   Foreground, Background, Tiledborder, Floatborder */
    [SchemeSel]          = { barfgalpha, barbgalpha, tlbrdralpha, flbrdralpha },
    [SchemeNorm]         = { barfgalpha, barbgalpha, tlbrdralpha, flbrdralpha },
    [SchemeStatusSel]    = { barfgalpha, barbgalpha, tlbrdralpha, flbrdralpha  },
    [SchemeStatusNorm]   = { barfgalpha, barbgalpha, tlbrdralpha, flbrdralpha  },
    [SchemeTagsSel]      = { barfgalpha, barbgalpha, tlbrdralpha, flbrdralpha },
    [SchemeTagsNorm]     = { barfgalpha, barbgalpha, tlbrdralpha, flbrdralpha },
    [SchemeInfoSel]      = { barfgalpha, barbgalpha, tlbrdralpha, flbrdralpha },
    [SchemeInfoNorm]     = { barfgalpha, barbgalpha, tlbrdralpha, flbrdralpha },
};
/*  DWM tags                                                                  */
static const char *tags[]                    = { "\uF015", "\uF09B", "\uF0AC",
                                                 "\uF04B", "\uF03D", "\uF130",
                                                 "\uF0D0", "\uF1B6", "\uF085" };
static const char *tagsalt[]                 = { "\uF22D", "\uF22D", "\uF22D",
                                                 "\uF22D", "\uF22D", "\uF22D",
                                                 "\uF22D", "\uF22D", "\uF22D" };
/*  DWM layout settings                                                       */
static const int dirs[3]         = { DirHor, DirVer, DirVer }; /* Tiling dirs */
static const float facts[3]      = { 1.1,    1.1,    1.1 }; /* Tiling facts   */
static const int nmaster         = 1; /* Number of clients in master area     */
static const int resizehints     = 0; /* 1 means size hints in tiled resizals */
static const int decorhints      = 1; /* 1 means respect decoration hints     */
static const int attachdirection = 5; /* 0 default, 1 above, 2 aside, 3 below,
                                                             4 bottom, 5 top  */
/*  DWM layout symbols                                                        */
static const Layout layouts[] = {
/*  Symbol        Layout                                                      */
    { "[+]",      tile }, /* Tiling layout with xtile behaviors patched in    */
    { "[*]",      NULL }, /* No layout function means floating behavior       */
    { "[M]",      monocle }, /* Classic monocle layout                        */
};
/*=====================================St=====================================*/
static const char *termcmd[]           = { "st", NULL };     /* NULL to close */
/*===================================Dmenu====================================*/
/*  Dmenu appearance settings                                                 */
static const char dmenufont[]          = "FreeMono:size=12";
static const char dmenuprompt[]        = "Launch";
/*  Dmenu color scheme                                                        */
static const char dmenuselfg[]         = "#eeeeee"; /* Dmenu selected fg      */
static const char dmenuselbg[]         = "#005577"; /* Dmenu selected bg      */
static const char dmenunrmfg[]         = "#bbbbbb"; /* Dmenu normal fg        */
static const char dmenunrmbg[]         = "#222222"; /* Dmenu normal bg        */
/*  Dmenu launch options                                                      */
static char dmenumon[2] = "0"; /* Component of dmenucmd, manipulated in spawn */
static const char *dmenucmd[] = { "dmenu_run",
                                  "-m", dmenumon, "-fn", dmenufont, /* font   */
                                  "-sf", dmenuselfg, "-sb", dmenuselbg, /*sel */
                                  "-nf", dmenunrmfg, "-nb", dmenunrmbg, /*norm*/
                                  "-p", dmenuprompt, NULL }; /* NULL to close */
/*===================================Extra====================================*/
/*  Helper for spawning shell commands in the pre dwm-5.0 fashion             */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }


/*====================================Keys====================================*/
/*  DWM macros                                                                */
#define MODKEY Mod4Mask
#define ALT Mod1Mask
#define WIN Mod4Mask
#define CTRL ControlMask
#define SHIFT ShiftMask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define TILEKEYS(MOD,G,M,S) \
	{ MOD, 27, setdirs,  {.v = (int[])  { INC(G * +1),   INC(M * +1),   INC(S * +1)   } } }, \
	{ MOD, 43, setfacts, {.v = (float[]){ INC(G * -0.1), INC(M * -0.1), INC(S * -0.1) } } }, \
	{ MOD, 46, setfacts, {.v = (float[]){ INC(G * +0.1), INC(M * +0.1), INC(S * +0.1) } } },
#define STACKKEYS(MOD,ACTION) \
	{ MOD, 44,     ACTION##stack, {.i = INC(+1) } }, \
	{ MOD, 45,     ACTION##stack, {.i = INC(-1) } }, \
	{ MOD, 51,     ACTION##stack, {.i = PREVSEL } }, \
	{ MOD, 25,     ACTION##stack, {.i = 0 } }, \
	{ MOD, 38,     ACTION##stack, {.i = 1 } }, \
	{ MOD, 52,     ACTION##stack, {.i = 2 } }, \
	{ MOD, 53,     ACTION##stack, {.i = -1 } },
/*  DWM keys and definitions                                                      */
static Key keys[] = {
	/* modifier                     key        function              argument */
	{ MODKEY,                       36,        spawn,         {.v = termcmd } },
	{ MODKEY|ShiftMask,             36,        spawn,        {.v = dmenucmd } },
	{ MODKEY,                       24,        killclient,                {0} },

	{ MODKEY,                       49,        setlayout,                 {0} },
	{ MODKEY|ShiftMask,             49,        setlayout,  {.v = &layouts[0]} },
	{ MODKEY|ControlMask,           49,        setlayout,  {.v = &layouts[1]} },
	{ MODKEY|ShiftMask|ControlMask, 49,        setlayout,  {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             57,        incnmaster,         {.i = +1 } },
	{ MODKEY|ControlMask,           57,        incnmaster,         {.i = -1 } },

	{ MODKEY,                       41,        setfullscreenfloating,     {0} },
	{ MODKEY|ShiftMask,             41,        setfullscreennative,       {0} },
	{ MODKEY|ControlMask,           41,        setfullscreenforced,       {0} },
	{ MODKEY|ShiftMask|ControlMask, 41,        setfullscreenlayout,       {0} },
	{ MODKEY,                       65,        togglefloating,            {0} },
	{ MODKEY|ControlMask,           55,        togglehorizontalmax,       {0} },
	{ MODKEY|ShiftMask,             55,        toggleverticalmax,         {0} },

	{ MODKEY|ShiftMask,             31,        setigaps,           {.i = +2 } },
	{ MODKEY|ControlMask,           31,        setigaps,           {.i = -2 } },
	{ MODKEY|ShiftMask|ControlMask, 31,        setigaps,           {.i = 0  } },
	{ MODKEY|ShiftMask,             32,        setogaps,           {.i = +2 } },
	{ MODKEY|ControlMask,           32,        setogaps,           {.i = -2 } },
	{ MODKEY|ShiftMask|ControlMask, 32,        setogaps,           {.i = 0  } },
	{ MODKEY,                       32,        togglegapsforone,          {0} },

	{ MODKEY,                       56,        togglebar,                 {0} },
	{ MODKEY|ShiftMask,             28,        togglealttag,              {0} },
	{ MODKEY|ControlMask,           28,        togglehidevactags,         {0} },
	
	{ MODKEY,                       59,        focusmon,           {.i = -1 } },
	{ MODKEY,                       60,        focusmon,           {.i = +1 } },
	{ MODKEY|ShiftMask,             59,        tagmon,             {.i = -1 } },
	{ MODKEY|ShiftMask,             60,        tagmon,             {.i = +1 } },
	{ MODKEY|ShiftMask,             23,        view,                      {0} },
	{ MODKEY,                       19,        view,              {.ui = ~0 } },
	{ MODKEY|ShiftMask,             19,        tag,               {.ui = ~0 } },
	TAGKEYS(                        10,                                    0)
	TAGKEYS(                        11,                                    1)
	TAGKEYS(                        12,                                    2)
	TAGKEYS(                        13,                                    3)
	TAGKEYS(                        14,                                    4)
	TAGKEYS(                        15,                                    5)
	TAGKEYS(                        16,                                    6)
	TAGKEYS(                        17,                                    7)
	TAGKEYS(                        18,                                    8)
	STACKKEYS(MODKEY,                                                  focus)
	STACKKEYS(MODKEY|ShiftMask,                                         push)
	TILEKEYS(MODKEY,                                                 1, 0, 0)
	TILEKEYS(MODKEY|ShiftMask,                                       0, 1, 0)
	TILEKEYS(MODKEY|ControlMask,                                     0, 0, 1)
	TILEKEYS(MODKEY|ShiftMask|ControlMask,                           1, 1, 1)
	{ MODKEY|ControlMask,           9,         quit,                      {0} },
};

/*===================================Buttons==================================*/
/*  DWM button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

/*===================================Rules====================================*/
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     iscentered   isfloating   isfreesize   isfakefullscreen   monitor */
	{ "Gimp",     NULL,       NULL,       0,            0,           1,           1,           0,                 -1      },
	{ "firefox",  NULL,       NULL,       0,            0,           0,           0,           1,                 -1      },
	{ "st",       NULL,       NULL,       0,            0,           0,           0,           0,                 -1      },
	{ "mpv",      NULL,       NULL,       0,            0,           0,           0,           0,                 -1      },
};
