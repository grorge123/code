# 其他設定

編輯vimrc

    sudo vim /etc/vim/vimrc
   
將下列新增到最下面

    set nu 
    set ts=4
    set expandtab
    set autoindent
# YouCompleteMe
vim 的自補充字體
## 初始化
    apt install build-essential cmake vim python3-dev git
## 安裝Vundle
    git clone https://github.com/gmarik/vundle.git ~/.vim/bundle/vundle
## 設定Vundle
    sudo vim /etc/vim/vimrc
將下列新增到vimrc

    set nocompatible              " be iMproved, required
    filetype off                  " required

    " set the runtime path to include Vundle and initialize
    set rtp+=~/.vim/bundle/vundle/
    call vundle#rc()
    " alternatively, pass a path where Vundle should install plugins
    "let path = '~/some/path/here'
    "call vundle#rc(path)

    " let Vundle manage Vundle, required
    Plugin 'gmarik/vundle'

    " The following are examples of different formats supported.
    " Keep Plugin commands between here and filetype plugin indent on.
    " scripts on GitHub repos
    Plugin 'tpope/vim-fugitive'
    Plugin 'Lokaltog/vim-easymotion'
    Plugin 'tpope/vim-rails.git'
    " The sparkup vim script is in a subdirectory of this repo called vim.
    " Pass the path to set the runtimepath properly.
    Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
    " scripts from http://vim-scripts.org/vim/scripts.html
    Plugin 'L9'
    Plugin 'FuzzyFinder'
    " scripts not on GitHub
    Plugin 'git://git.wincent.com/command-t.git'
    " git repos on your local machine (i.e. when working on your own plugin)
    Plugin 'file:///home/gmarik/path/to/plugin'
    " ...

    filetype plugin indent on     " required
    " To ignore plugin indent changes, instead use:
    "filetype plugin on
    "
    " Brief help
    " :PluginList          - list configured plugins
    " :PluginInstall(!)    - install (update) plugins
    " :PluginSearch(!) foo - search (or refresh cache first) for foo
    " :PluginClean(!)      - confirm (or auto-approve) removal of unused plugins
    "
    " see :h vundle for more details or wiki for FAQ
    " NOTE: comments after Plugin commands are not allowed.
    " Put your stuff after this line
    
並且將下列新增到Plugin 'L9'下面

    Plugin 'Valloric/YouCompleteMe'    

## 下載youcompleteme

## 編譯youcompleteme

## BUG 修復
