/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 5;       /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Monofur:size=14" };
static const char dmenufont[]       = "Mononoki:size=10";
static const char col_gray1[]       = "#1e1f29";
static const char col_gray2[]       = "#f197ac";
static const char col_gray3[]       = "#f197ac";
static const char col_gray4[]       = "#1e1f29";
static const char col_cyan[]        = "#f179ac";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[] = { "st", NULL };
static const char *kitty[]  = { "kitty", NULL };
static const char *browser[] = { "brave", NULL };
static const char *rpcs3[] = { "rpcs3", NULL };
static const char *imagewriter[] = { "imagewriter", NULL };
static const char *obs[] = { "obs", NULL };
static const char *pcmanfm[] = { "pcmanfm", NULL };
static const char *pulsemixer[] = { "st", "-e", "pulsemixer", NULL };
static const char *lxappearance[] = { "lxappearance", NULL };
static const char *steam[] = { "steam-native", NULL };
static const char *spotify[] = { "spotify", NULL };
static const char *rofi[] = { "rofi", "-modi", "drun", "-show", "drun", "-show-icons", NULL };
static const char *dolphin[] = { "dolphin-emu", NULL };
static const char *htop[] = { "st", "-e", "htop", NULL };
static const char *joshuto[]  = { "st", "-e", "joshuto", NULL };
static const char *lutris[] = { "lutris", NULL };
static const char *lf[] = { "st", "-e", "lf", NULL };
static const char *clonehero[] = { "/home/gray/.clonehero/clonehero", NULL };
static const char *nitrogen[] = { "nitrogen", NULL };
static const char *minecraft[] = { "minecraft-launcher", NULL };
static const char *suspend[] = { "st", "-e", "sudo", "systemctl", "suspend", "&&", "betterlockscreen", "-l", NULL };
static const char *shutdown[] = { "shutdown", "now", NULL };
static const char *reboot[] = { "reboot", NULL };
static const char *upvol[] = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "+5%", NULL };
static const char *downvol[] = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "-5%", NULL };
static const char *mutevol[] = { "/usr/bin/pactl", "set-sink-mute", "@DEFAULT_SINK@", "toggle", NULL };
static const char *play[] = { "playerctl", "play-pause", NULL };
static const char *prev[] = { "playerctl", "previous", NULL };
static const char *next[] = { "playerctl", "next", NULL };

#include <X11/XF86keysym.h>

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = rofi } },
	{ MODKEY|ShiftMask,		XK_d,	   spawn,	   {.v = dolphin  } },
	{ MODKEY,	                XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,		XK_Return, spawn,	   {.v = kitty } },
	{ MODKEY,			XK_w,	   spawn,	   {.v = browser } },
	{ MODKEY,			XK_r,	   spawn,	   {.v = rpcs3 } },
	{ MODKEY,			XK_i,	   spawn,	   {.v = imagewriter } },
	{ MODKEY,			XK_o,	   spawn,	   {.v = obs } },
	{ MODKEY,			XK_p,	   spawn,	   {.v = pcmanfm } },
	{ MODKEY|ShiftMask,		XK_p,	   spawn,	   {.v = pulsemixer } },
	{ MODKEY|ShiftMask,		XK_a,	   spawn,	   {.v = lxappearance } },
	{ MODKEY,			XK_s,	   spawn,	   {.v = steam } },
	{ MODKEY|ShiftMask,		XK_s,	   spawn,	   {.v = spotify } },
	{ MODKEY|ShiftMask,		XK_h,	   spawn,	   {.v = htop } },
	{ MODKEY|ShiftMask,		XK_j,	   spawn,	   {.v = joshuto } },
	{ MODKEY,			XK_l,	   spawn,	   {.v = lutris } },
	{ MODKEY|ShiftMask,		XK_l,	   spawn,	   {.v = lf } },
	{ MODKEY,			XK_c,	   spawn,	   {.v = clonehero } },
	{ MODKEY,			XK_n,	   spawn,	   {.v = nitrogen } },
	{ MODKEY,			XK_m,	   spawn,	   {.v = minecraft } },
	{ MODKEY,			XK_x,	   spawn,	   {.v = suspend } },
	{ MODKEY|ShiftMask,		XK_x,	   spawn,	   {.v = shutdown } },
	{ MODKEY|ShiftMask,		XK_q,	   spawn,  {.v = reboot } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	/* { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} }, */
	{ MODKEY,	                XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_Left,  focusmon,        {.i = -1 } },
	{ MODKEY,                       XK_Right, focusmon,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Left,  tagmon,          {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Right, tagmon,          {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_BackSpace,      quit,           {0} },
	{ 0, XF86XK_AudioRaiseVolume, 	spawn,		{.v = upvol } },
	{ 0, XF86XK_AudioLowerVolume,	spawn,		{.v = downvol } },
	{ 0, XF86XK_AudioMute,		spawn,		{.v = mutevol } },
	{ 0, XF86XK_AudioPlay,		spawn,		{.v = play } },
	{ 0, XF86XK_AudioPrev,		spawn,		{.v = prev } },
	{ 0, XF86XK_AudioNext,		spawn,		{.v = next } },
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

