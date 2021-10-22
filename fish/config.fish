if status is-interactive
    # Commands to run in interactive sessions can go here
end

set fish_greeting
xset r rate 350 50 &
alias yeet='yay -Rcs'
alias ls='ls -lah --color=auto'
alias i3='vim ~/.config/i3/config'
alias i3status='vim ~/.config/i3/i3status.conf'
alias dwm='cd ~/.config/dwm && vim config.h'
alias slstatus='cd ~/.config/slstatus && vim config.h'
alias stconf='cd ~/.config/st && vim config.h'
alias fishconf='vim ~/.config/fish/config.fish'
alias kittyconf='vim ~/.config/kitty/kitty.conf'
alias bspwm='vim ~/.config/bspwm/bspwmrc'
alias sxhkd='vim ~/.config/sxhkd/sxhkdrc'
alias sleep='systemctl suspend && betterlockscreen -l'
alias kwayland='XDG_SESSION_TYPE=wayland dbus-run-session startplasma-wayland'

#function fish_prompt
#  set_color c197ac
#  echo -n ""
  # winter
  #set_color 198c8c
  #echo -n ">"
  #set_color b0e0e6
  #echo -n ">"
  #set_color e7f5f7
  #echo -n ">"

   # fire
#  set_color f6412d
#  echo -n ">"
#  set_color ff9800
#  echo -n ">"
#  set_color ffc100
#  echo -n ">"
#  set_color ffec19
#  echo -n ">"

  # rainbow prompt
 # set_color e32636
 # echo -n ">"
 # set_color ff8d00
 # echo -n ">"
 # set_color 00dc6e
 # echo -n ">"
 # set_color 006eca
 # echo -n ">"

   # shiverwind
#    echo -n ">"
#   set_color bf72ff
#   echo -n ">"
#   set_color 6db5f9
#   echo -n ">"
#   set_color 76f69c
#   echo -n ">"

# end
#   echo -n "|"
#   echo -n (prompt_pwd)
#   echo -n "|"
#   echo -n " "

#end
