/*  See LICENSE file for copyright and license details.                       */

/*  DWM settings                                                              */
/*  DWM appearance settings                                                   */
static const int showbar            = 1; /* 0 means no bar                    */
static const int topbar             = 1; /* 0 means bottom bar                */
static const int barheight          = 26;/* Specific bar height (0 means def) */
static const int startontag         = 1; /* 0 means no tag is active on start */
static const int gapsforone         = 0; /* Gaps for only one window open     */
static const unsigned int igappx    = 5; /* Size of inner gaps                */
static const unsigned int ogappx    = 5; /* Size of outer gaps                */
static const unsigned int snap      = 32;/* Snap pixel                        */
static const unsigned int borderpx  = 1; /* Border pixel of windows           */
static const char *fonts[]          = { "FreeMono:size=10", /* Primary        */
                                        "FreeSerif:size=10", /* Secondary     */
                                        "FontAwesome:size=10" }; /* Iconic    */
/*  DWM color scheme                                                          */
static const char ltsymfgsel[]      = "#222222"; /* Layout symbol fg selected */
static const char ltsymbgsel[]      = "#222222"; /* Layout symbol bg selected */
static const char tlbrdrsel[]       = "#444444"; /* Tiled border selected     */
static const char flbrdrsel[]       = "#005577"; /* Floating border selected  */
static const char ltsymfgnrm[]      = "#bbbbbb"; /* Layout symbol fg normal   */
static const char ltsymbgnrm[]      = "#222222"; /* Layout symbol bg normal   */
static const char tlbrdrnrm[]       = "#444444"; /* Tiled border normal       */
static const char flbrdrnrm[]       = "#444444"; /* Floating border normal    */
static const char statusfg[]        = "#bbbbbb"; /* Status bar fg             */
static const char statusbg[]        = "#222222"; /* Status bar bg             */
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
    [SchemeStatus]         = { statusfg,   statusbg,   unusedcol,  unusedcol  },
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
    [SchemeStatus]       = { barfgalpha, barbgalpha, tlbrdralpha, flbrdralpha },
    [SchemeTagsSel]      = { barfgalpha, barbgalpha, tlbrdralpha, flbrdralpha },
    [SchemeTagsNorm]     = { barfgalpha, barbgalpha, tlbrdralpha, flbrdralpha },
    [SchemeInfoSel]      = { barfgalpha, barbgalpha, tlbrdralpha, flbrdralpha },
    [SchemeInfoNorm]     = { barfgalpha, barbgalpha, tlbrdralpha, flbrdralpha },
};
/*  DWM tags                                                                  */
static const char *tags[]                    = { "\uF2BE", "\uF09B", "\uF0AC",
                                                 "\uF04B", "\uF03D", "\uF130",
                                                 "\uF0D0", "\uF1B6", "\uF085" };
static const char *tagsalt[]                 = { "\uF22D", "\uF22D", "\uF22D",
                                                 "\uF22D", "\uF22D", "\uF22D",
                                                 "\uF22D", "\uF22D", "\uF22D" };
/*  DWM layouts                                                               */
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
/*  Dmenu settings                                                            */
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
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont,
                                  "-sf", dmenuselfg, "-sb", dmenuselbg, /*sel */
                                  "-nf", dmenunrmfg, "-nb", dmenunrmbg, /*norm*/
                                  "-p", dmenuprompt, NULL }; /* NULL to close */
/*  St appearance settings                                                    */
/*  St color scheme                                                           */
/*  St launch options                                                         */
static const char *termcmd[]  = { "st", NULL };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     iscentered   isfloating   isfreesize   isfakefullscreen   monitor */
	{ "Gimp",     NULL,       NULL,       0,            0,           1,           1,           0,                 -1      },
	{ "firefox",  NULL,       NULL,       0,            0,           0,           0,           1,                 -1      },
	{ "st",       NULL,       NULL,       0,            0,           0,           0,           0,                 -1      },
	{ "St",       NULL,       NULL,       0,            0,           0,           0,           0,                 -1      },
	{ "mpv",      NULL,       NULL,       0,            0,           0,           0,           0,                 -1      },
};

/* key definitions */
#define MODKEY Mod1Mask
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
	{ MOD, XK_r, setdirs,  {.v = (int[])  { INC(G * +1),   INC(M * +1),   INC(S * +1) } } }, \
	{ MOD, XK_h, setfacts, {.v = (float[]){ INC(G * -0.1), INC(M * -0.1), INC(S * -0.1) } } }, \
	{ MOD, XK_l, setfacts, {.v = (float[]){ INC(G * +0.1), INC(M * +0.1), INC(S * +0.1) } } },
#define STACKKEYS(MOD,ACTION) \
	{ MOD, XK_j,     ACTION##stack, {.i = INC(+1) } }, \
	{ MOD, XK_k,     ACTION##stack, {.i = INC(-1) } }, \
	{ MOD, XK_grave, ACTION##stack, {.i = PREVSEL } }, \
	{ MOD, XK_q,     ACTION##stack, {.i = 0 } }, \
	{ MOD, XK_a,     ACTION##stack, {.i = 1 } }, \
	{ MOD, XK_z,     ACTION##stack, {.i = 2 } }, \
	{ MOD, XK_x,     ACTION##stack, {.i = -1 } },
 
/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	STACKKEYS(MODKEY,                          focus)
	STACKKEYS(MODKEY|ShiftMask,                push)
	TILEKEYS(MODKEY,                                           1, 0, 0)
	TILEKEYS(MODKEY|ShiftMask,                                 0, 1, 0)
	TILEKEYS(MODKEY|ControlMask,                               0, 0, 1)
	TILEKEYS(MODKEY|ShiftMask|ControlMask,                     1, 1, 1)
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_f,      forcefullscreen,     {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_i,      setigaps,       {.i = +2 } },
	{ MODKEY|ControlMask,           XK_i,      setigaps,       {.i = -2 } },
	{ MODKEY|ShiftMask|ControlMask, XK_i,      setigaps,       {.i = 0  } },
	{ MODKEY|ShiftMask,             XK_o,      setogaps,       {.i = +2 } },
	{ MODKEY|ControlMask,           XK_o,      setogaps,       {.i = -2 } },
	{ MODKEY|ShiftMask|ControlMask, XK_o,      setogaps,       {.i = 0  } },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_n,      togglealttag,   {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask|ControlMask,             XK_BackSpace, quit,        {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

