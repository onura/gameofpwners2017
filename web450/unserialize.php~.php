<?php

class vuln {
  public $path = __DIR__;
  public $switch = true;

  function __destruct() {
    if ($this->switch) {
        print_r(scandir($this->path."/empty"));
    } else {
        echo file_get_contents($this->path);
    }
  }
}

if(isset($_POST['vulnobj']) && !empty($_POST['vulnobj'])) {
  unserialize($_POST['vulnobj']);
} else {
  $vulnobj = new vuln;
  $vulnobj->switch = true;
}

?>
