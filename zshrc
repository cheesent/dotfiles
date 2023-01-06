# Enable Powerlevel10k instant prompt. Should stay close to the top of ~/.zshrc.
# Initialization code that may require console input (password prompts, [y/n]
# confirmations, etc.) must go above this block; everything else may go below.
#if [[ -r "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh" ]]; then
#  source "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh"
#fi

# Lines configured by zsh-newuser-install
HISTFILE=~/.histfile
HISTSIZE=1000
SAVEHIST=1000
bindkey -v
# End of lines configured by zsh-newuser-install
# The following lines were added by compinstall
zstyle :compinstall filename '/home/vicent/.zshrc'

autoload -Uz compinit
compinit
# End of lines added by compinstall


#source ~/powerlevel10k/powerlevel10k.zsh-theme

# To customize prompt, run `p10k configure` or edit ~/.p10k.zsh.
[[ ! -f ~/.p10k.zsh ]] || source ~/.p10k.zsh

# Custom Aliases
alias cat='bat'
alias ll='lsd -lh --group-dirs=first'
alias la='lsd -a --group-dirs=first'
alias l='lsd --group-dirs=first'
alias lla='lsd -lha --group-dirs=first'
alias ls='lsd --group-dirs=first'
alias catn='/bin/cat'
alias catnp='bat --no-paging'
alias ard='arduino-cli'
alias whisper='/home/vicent/.local/bin/whisper'

#####################################################
# Auto completion / suggestion
# Mixing zsh-autocomplete and zsh-autosuggestions
# Requires: zsh-autocomplete (custom packaging by Parrot Team)

# Jobs: Fish-like suggestion for command history
source /usr/share/zsh/plugins/zsh-autosuggestions/zsh-autosuggestions.zsh 
#source /usr/share/zsh-autocomplete/zsh-autocomplete.plugin.zsh
# Select all suggestion instead of top on result only
zstyle ':autocomplete:tab:*' insert-unambiguous yes
zstyle ':autocomplete:tab:*' widget-style menu-select
zstyle ':autocomplete:*' min-input 2
#bindkey $key[Up] up-line-or-history
#bindkey $key[Down] down-line-or-history

##################################################
# Fish like syntax highlighting
# Requires "zsh-syntax-highlighting" from apt

source /usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh 

# Vi mode
#bindkey -v
#export KEYTIMEOUT=1

bindkey "^[[H" beginning-of-line
bindkey "^[[F" end-of-line
bindkey "^[[3~" delete-char
# Salto de palabra hacia la derecha
bindkey "^[[1;2C" forward-word
# Salto de palabra hacia la izquierda
bindkey "^[[1;2D" backward-word

# Save type history for completion and easier life
HISTFILE=~/.zsh_history
HISTSIZE=1000
SAVEHIST=1000
# setopt appendhistory
setopt histignorealldups sharehistory

# Useful alias for benchmarking programs
# require install package "time" sudo apt install time
# alias time="/usr/bin/time -f '\t%E real,\t%U user,\t%S sys,\t%K amem,\t%M mmem'"
# Display last command interminal
#echo -en "\e]2;Parrot Terminal\a"
#preexec () { print -Pn "\e]0;$1 - Parrot Terminal\a" }

source ~/powerlevel10k/powerlevel10k.zsh-theme

# Use modern completion system
autoload -Uz compinit
compinit

zstyle ':completion:*' auto-description 'specify: %d'
zstyle ':completion:*' completer _expand _complete _correct _approximate
zstyle ':completion:*' format 'Completing %d'
zstyle ':completion:*' group-name ''
zstyle ':completion:*' menu select=2
eval "$(dircolors -b)"
zstyle ':completion:*:default' list-colors ${(s.:.)LS_COLORS}
zstyle ':completion:*' list-colors ''
zstyle ':completion:*' list-prompt %SAt %p: Hit TAB for more, or the character to insert%s
zstyle ':completion:*' matcher-list '' 'm:{a-z}={A-Z}' 'm:{a-zA-Z}={A-Za-z}' 'r:|[._-]=* r:|=* l:|=*'
zstyle ':completion:*' menu select=long
zstyle ':completion:*' select-prompt %SScrolling active: current selection at %p%s
zstyle ':completion:*' use-compctl false
zstyle ':completion:*' verbose true

zstyle ':completion:*:*:kill:*:processes' list-colors '=(#b) #([0-9]#)*=0=01;31'
zstyle ':completion:*:kill:*' command 'ps -u $USER -o pid,%cpu,tty,cputime,cmd'

[ -f ~/.fzf.zsh ] && source ~/.fzf.zsh

##Vim mode
zle



