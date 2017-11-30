
Pod::Spec.new do |s|

    s.name = 'KZ_VideoPlayer'
    s.version = '0.1.1'
    s.summary = 'iOS video player.'
    s.homepage = 'https://github.com/KieronZhang/KZ_VideoPlayer'
    s.license = {:type => 'MIT', :file => 'LICENSE'}
    s.author = {'KieronZhang.' => 'https://github.com/KieronZhang'}
    s.platform = :ios, '8.0'
    s.source = {:git => 'https://github.com/KieronZhang/KZ_VideoPlayer.git', :tag => s.version, :submodules => true}
    s.xcconfig = {'OTHER_LDFLAGS' => '-ObjC'}
    s.resource = 'KZ_VideoPlayer/KZ_VideoPlayerBundle.bundle'
    s.frameworks = 'UIKit', 'Foundation', 'AVFoundation', 'MediaPlayer'
    s.vendored_frameworks = 'KZ_VideoPlayer/KZ_VideoPlayerFramework.framework'
    s.requires_arc = true

    s.dependency 'Masonry'
    s.dependency 'KZ_Categories'

end
