
Pod::Spec.new do |s|

    s.name = 'KZ_VideoPlayer'
    s.version = '0.1.2'
    s.summary = 'iOS video player.'
    s.homepage = 'https://github.com/KieronZhang/KZ_VideoPlayer'
    s.license = {:type => 'MIT', :file => 'LICENSE'}
    s.author = {'KieronZhang' => 'https://github.com/KieronZhang'}

    s.source = {:git => 'https://github.com/KieronZhang/KZ_VideoPlayer.git', :tag => s.version, :submodules => true}
    s.xcconfig = {'OTHER_LDFLAGS' => '-ObjC'}
    s.requires_arc = true

    s.ios.frameworks = 'UIKit', 'Foundation', 'AVFoundation', 'MediaPlayer'

    s.ios.deployment_target = '8.0'

    s.ios.vendored_frameworks = 'KZ_VideoPlayer/KZ_VideoPlayer_iOS.framework'

    s.ios.resource = 'KZ_VideoPlayer/KZ_VideoPlayer_Bundle.bundle'

    s.dependency 'KZ_Constraints'
    s.dependency 'KZ_Categories'

end
