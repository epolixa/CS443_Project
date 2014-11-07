# vagrant/puppet/modules/mysql/manifests/init.pp
class bootstrap {

  exec { 'setup-node':
    unless => 'which node',
    command => 'curl -sL https://deb.nodesource.com/setup | sudo bash -',
    path => ['/bin', '/usr/bin'],
    require => [Exec['apt-get update'], Package['curl']],
  }

  package { ['nodejs']:
    ensure => latest,
    require => Exec['setup-node'],
  }

  file { '/bootstrap':
    ensure => 'link',
    target => '/vagrant/bootstrap-3.3.0',
  }

  file { '/var/www/app/css/bootstrap.min.css':
    ensure => 'link',
    target => '../../bootstrap-3.3.0/dist/css/bootstrap.min.css',
    require => File['/bootstrap'],
  }
  
  file { '/var/www/app/css/bootstrap.css.map':
    ensure => 'link',
    target => '../../bootstrap-3.3.0/dist/css/bootstrap.css.map',
    require => File['/bootstrap'],
  }

  file { '/var/www/app/js/bootstrap.min.js':
    ensure => 'link',
    target => '../../bootstrap/-3.3.0dist/js/bootstrap.min.js',
    require => File['/bootstrap'],
  }
  
  file { '/var/www/app/fonts':
    ensure => 'link',
    target => '../bootstrap-3.3.0/dist/fonts',
    require => File['/bootstrap'],
  }

  exec { 'install-less-global':
    unless => 'which lessc',
    command => 'npm install -g less',
    path => ['/bin', '/usr/bin'],
    require => Package['nodejs'],
  }

  exec { 'install-grunt-global':
    unless => 'which grunt',
    command => 'npm install -g grunt-cli',
    path => ['/bin', '/usr/bin'],
    require => Package['nodejs'],
  }
  
  exec { 'install-bootstrap-deps':
    creates => '/bootstrap/node_modules',
    command => 'npm install',
    cwd => '/bootstrap',
    path => ['/bin', '/usr/bin'],
    require => [Exec['install-grunt-global'],File['/bootstrap']],
  }
}
