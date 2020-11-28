/*             See LICENSE file for copyright and license details.            */
/*====================================DWM=====================================*/
/*  DWM appearance settings                                                   */
static int gapsforone               = 0; /* Gaps for only one window open     */
static int hidevactags              = 0; /* Hide vacant tags                  */
static int viewontag                = 1; /* 1 Switch view on tag switch       */
static int warponfocus              = 1; /* 1 Warp pointer to focused client  */
static const int topbar             = 1; /* 0 means bottom bar                */
static const int showbar            = 1; /* 0 means no bar                    */
static const int showextrabar       = 1; /* 0 means no extra bar              */
static const int barheight          = 26;/* Specific bar height (0 for def)   */
static const int extrabarheight     = 16;/* Specific bar height (0 for def)   */
static const int startontag         = 1; /* 0 means no tag is active on start */
static const int swallowfloating    = 0; /* 1 swallow all floating windows    */
static const int showsystray        = 1; /* 0 means no systray                */
static const int stfallbackmon      = 1; /* 1 means first monitor, 0 last     */
static const unsigned int stmonitor = 0; /* 0 means selected monitor          */
static const unsigned int stspacing = 2; /* systray spacing                   */
static const unsigned int igappx    = 5; /* Size of inner gaps                */
static const unsigned int ogappx    = 5; /* Size of outer gaps                */
static const unsigned int snap      = 32;/* Snap pixel                        */
static const unsigned int borderpx  = 1; /* Border pixel of windows           */
static const char *fonts[]          = { "FreeMono:size=12", /* Primary        */
                                        "FreeSerif:size=12", /* Secondary     */
                                        "FontAwesome:size=10" }; /* Iconic    */
/*  DWM color scheme                                                          */
static const char barselfg[]        = "#eeeeee"; /* Bar foreground selected   */
static const char barselbg[]        = "#fc6e02"; /* Bar background selected   */
static const char tlbrdsel[]        = "#fc6e02"; /* Tiled border selected     */
static const char flbrdsel[]        = "#fc6e02"; /* Floating border selected  */
static const char urbrdsel[]        = "#ff0202"; /* Urgent border selected    */
static const char barnrmfg[]        = "#bbbbbb"; /* Bar foreground normal     */
static const char barnrmbg[]        = "#222222"; /* Bar background normal     */
static const char tlbrdnrm[]        = "#444444"; /* Tiled border normal       */
static const char flbrdnrm[]        = "#444444"; /* Floating border normal    */
static const char urbrdnrm[]        = "#ff0202"; /* Urgent border normal      */
static const char *colors[][5]      = {
/*  Scheme           Foreground, Background, TileBorder, FltBorder, UrgBorder */
    [SchemeSel]  = { barselfg,   barselbg,   tlbrdsel,   flbrdsel,  urbrdsel  },
    [SchemeNorm] = { barnrmfg,   barnrmbg,   tlbrdnrm,   flbrdnrm,  urbrdnrm  },
};
/*  DWM Alpha scheme                                                          */
static const unsigned int barfgA           = 0xffU; /* Opaque foreground      */
static const unsigned int barbgA           = 0xd0;  /* Transparent background */
static const unsigned int tlbrdA           = 0xffU; /* Opaque tiled border    */
static const unsigned int flbrdA           = 0xffU; /* Opaque floating border */
static const unsigned int urbrdA           = 0xffU; /* Opaque urgent border   */
static const unsigned int alphas[][5]      = {
/*  Scheme           Foreground, Background, TileBorder, FltBorder, UrgBorder */
    [SchemeSel]  = { barfgA,     barbgA,     tlbrdA,     flbrdA,    urbrdA    },
    [SchemeNorm] = { barfgA,     barbgA,     tlbrdA,     flbrdA,    urbrdA    },
};
/*  DWM tags                                                                  */
static const char *tags[]                    = { "\uF406", "\uF269", "\uF09B",
                                                 "\uF04B", "\uF03D", "\uF130",
                                                 "\uF0D0", "\uF1B6", "\uF085" };
static const char *tagsalt[]                 = { "\uF4FC", "\uF4FF", "\uF501",
                                                 "\uF505", "\uF508", "\uF507",
                                                 "\uF4FB", "\uF4FD", "\uF4FE" };
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
    { NULL,       NULL },
};
/*=====================================St=====================================*/
static const char *termcmd[]           = { "st", NULL };          /* Terminal */
static const char *dwmman[]            = { "st", "man", "dwm", NULL }; /* MAN */
/*===================================Dmenu====================================*/
/*  Dmenu appearance settings                                                 */
static const char dmenufont[]          = "FreeMono:size=12";
static const char dmenuprompt[]        = "Launch";
/*  Dmenu launch options                                                      */
static char dmenumon[2] = "0"; /* Component of dmenucmd, manipulated in spawn */
static const char *dmenucmd[] = { "dmenu_run",
                                  "-m", dmenumon, "-fn", dmenufont, /* font   */
                                  "-sf", barselfg, "-sb", barselbg, /* select */
                                  "-nf", barnrmfg, "-nb", barnrmbg, /* normal */
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
	{ MOD, 45,     ACTION##stack, {.i = INC(+1) } }, \
	{ MOD, 44,     ACTION##stack, {.i = INC(-1) } }, \
	{ MOD, 24,     ACTION##stack, {.i = PREVSEL } }, \
	{ MOD, 25,     ACTION##stack, {.i = 0 } }, \
	{ MOD, 38,     ACTION##stack, {.i = 1 } }, \
	{ MOD, 52,     ACTION##stack, {.i = 2 } }, \
	{ MOD, 53,     ACTION##stack, {.i = -1 } },
/*  DWM keys and definitions                                                      */
static Key keys[] = {
	/* modifier                     key        function              argument */
	{ MODKEY,                       36,        spawn,         {.v = termcmd } },
	{ MODKEY,                       22,        spawn,        {.v = dmenucmd } },

	{ MODKEY,                       49,        setlayout,                 {0} },
	{ MODKEY|ShiftMask,             49,        cyclelayout,        {.i = +1 } },
	{ MODKEY|ControlMask,           49,        cyclelayout,        {.i = -1 } },
	{ MODKEY|ShiftMask,             57,        incnmaster,         {.i = +1 } },
	{ MODKEY|ControlMask,           57,        incnmaster,         {.i = -1 } },

	{ MODKEY,                       41,        setfullscreenlayout,       {0} },
	{ MODKEY|ShiftMask,             41,        setfullscreennative,       {0} },
	{ MODKEY|ControlMask,           41,        setfullscreenforced,       {0} },
	{ MODKEY,                       65,        togglefloating,            {0} },

	{ MODKEY|ShiftMask,             31,        setigaps,           {.i = +2 } },
	{ MODKEY|ControlMask,           31,        setigaps,           {.i = -2 } },
	{ MODKEY|ShiftMask|ControlMask, 31,        setigaps,           {.i = 0  } },
	{ MODKEY|ShiftMask,             32,        setogaps,           {.i = +2 } },
	{ MODKEY|ControlMask,           32,        setogaps,           {.i = -2 } },
	{ MODKEY|ShiftMask|ControlMask, 32,        setogaps,           {.i = 0  } },
	{ MODKEY,                       32,        togglegapsforone,          {0} },
	{ MODKEY|ShiftMask,             33,        setborderpx,        {.i = +1 } },
	{ MODKEY|ControlMask,           33,        setborderpx,        {.i = -1 } },
	{ MODKEY|ShiftMask|ControlMask, 33,        setborderpx,         {.i = 0 } },

	{ MODKEY,                       56,        togglebar,           {.i = 0 } },
	{ MODKEY|ShiftMask,             56,        togglebar,           {.i = 1 } },
	{ MODKEY|ControlMask,           56,        togglebar,           {.i = 2 } },
	{ MODKEY|ShiftMask|ControlMask, 56,        togglebar,          {.i = -1 } },
	{ MODKEY|ShiftMask,             28,        togglealttag,              {0} },
	{ MODKEY|ControlMask,           28,        togglehidevactags,         {0} },

	{ MODKEY,                       118,       toggleviewontag,           {0} },
	{ MODKEY,                       119,       togglewarp,                {0} },

	{ MODKEY,                       59,        focusmon,           {.i = -1 } },
	{ MODKEY,                       60,        focusmon,           {.i = +1 } },
	{ MODKEY|ShiftMask,             59,        tagmon,             {.i = -1 } },
	{ MODKEY|ShiftMask,             60,        tagmon,             {.i = +1 } },

	{ MODKEY,                       23,        view,                      {0} },
	{ MODKEY|ShiftMask,             23,        shiftview,          {.i = +1 } },	
	{ MODKEY|ControlMask,           23,        shiftview,          {.i = -1 } },
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
	{ MODKEY|ControlMask,           127,       togglekeys,                {0} },
	{ MODKEY,                       9,         killclient,                {0} },
	{ MODKEY|ShiftMask,             9,         killunsel,                 {0} },
	{ MODKEY|ShiftMask|ControlMask, 9,         quit,                      {0} },
};
static Key altkeys[] = {
	/* modifier                     key        function              argument */
	{ MODKEY|ControlMask,           127,       togglekeys,                {0} },
};

/*===================================Buttons==================================*/
/*  DWM button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkUser,              0,              Button1,        spawn,          {.v = termcmd } },
	{ ClkUser,              0,              Button3,        spawn,          {.v = dmenucmd } },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkLtSymbol,          0,              Button2,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button1,        cyclelayout,    {.i = +1 } },
	{ ClkLtSymbol,          0,              Button3,        cyclelayout,    {.i = -1 } },
	{ ClkPower,             0,              Button1,        setlayout,      {0} },
	{ ClkLock,              0,              Button1,        setogaps,       {.i = -2 } },
	{ ClkKeyboard,          0,              Button1,        spawn,          {.v = dwmman } },
	{ ClkLanguage,          0,              Button1,        setogaps,       {.i = +2 } },

	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },

	{ ClkStatusText,        0,              Button1,        spawn,          {.v = termcmd } },
};

/*===================================Rules====================================*/
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class           instance    title              tags mask     switchtotag   iscentered   isfloating   isfreesize   isfakefullscreen   isterminal   noswallow   ispermanent   monitor */
	{ NULL,            NULL,       "Event Tester",    0,            0,            0,           1,           1,           0,                 0,           1,          0,            -1      },
	{ "firefox",       NULL,       NULL,              1 << 1,       1,            0,           0,           0,           1,                 0,           -1,         0,            -1      },
	{ "code-oss",      NULL,       NULL,              1 << 2,       1,            0,           0,           0,           0,                 0,           0,          0,            -1      },
	{ "Steam",         NULL,       NULL,              1 << 7,       1,            0,           1,           1,           0,                 0,           0,          1,            -1      },
	{ "Gimp",          NULL,       NULL,              1 << 6,       1,            0,           1,           1,           0,                 0,           0,          0,            -1      },
	{ "st",            NULL,       NULL,              0,            0,            0,           0,           0,           0,                 1,           0,          0,            -1      },
	{ "mpv",           NULL,       NULL,              0,            0,            0,           0,           0,           0,                 0,           0,          0,            -1      },
};
