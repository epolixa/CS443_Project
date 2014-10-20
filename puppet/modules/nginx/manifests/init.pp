# vagrant/puppet/modules/nginx/manifests/init.pp
class nginx {
    file { '/var/www/app':
    ensure => 'link',
      target => '/vagrant/app',
    }
    
    package { 'nginx':
      ensure => 'present',
      require => Exec['apt-get update'],
      }

    service { 'nginx':
      ensure => running,
      require => Package['nginx'],
      }

    file { 'vagrant-nginx':
      path => '/etc/nginx/sites-available/127.0.0.1',
      ensure => file,
      require => Package['nginx'],
      source => 'puppet:///modules/nginx/127.0.0.1',
      }

    file { 'default-nginx-disable':
      path => '/etc/nginx/sites-enabled/default',
      ensure => absent,
      require => Package['nginx'],
      }

    file { 'vagrant-nginx-enable':
      path => '/etc/nginx/sites-enabled/127.0.0.1',
      target => '/etc/nginx/sites-available/127.0.0.1',
      ensure => link,
      notify => Service['nginx'],
      require => [
                  File['vagrant-nginx'],
                  File['default-nginx-disable'],
                  ],
      }
    }
